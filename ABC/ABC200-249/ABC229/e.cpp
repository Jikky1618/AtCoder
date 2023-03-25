#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

struct UnionFind {
	int n, group_size;
	vector<int> parent_or_size;

	UnionFind(int size): n(size), group_size(size), parent_or_size(size, -1) {}

	int root(int x){
		return (parent_or_size[x] < 0 ? x : parent_or_size[x] = root(parent_or_size[x]));
	}

	bool same(int x, int y){
		return root(x) == root(y);
	}

	bool merge(int x, int y){
		int rx = root(x), ry = root(y);
		if(rx == ry) return false;
		if(-parent_or_size[rx] < -parent_or_size[ry]) swap(rx, ry); 
		parent_or_size[rx] += parent_or_size[ry]; 
		parent_or_size[ry] = rx;
		group_size--;
		return true;
	}

	int size(int x){
		return -parent_or_size[root(x)];
	}

	int group_count(){
		return group_size;
	}

	vector<int> group(int x){
		vector<int> res;
		for(int i = 0; i < n; i++){
			if(same(x, i)) res.push_back(i);
		}
		return res;
	}

	vector<vector<int>> groups(){
		vector<vector<int>> res(n);
		for(int i = 0; i < n; i++){
			res[root(i)].push_back(i);
		}
		res.erase(remove_if(res.begin(), res.end(), [&](const vector<int>& v){
			return v.empty();
		}), res.end());
		return res;
	}
};

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int N, M;
	cin >> N >> M;
	vector<vector<int>> G(N);
	for(int i = 0; i < M; i++){
		int A, B; cin >> A >> B, A--, B--;
		G[A].push_back(B);
		G[B].push_back(A);
	}

	UnionFind uf(N);
	vector<int> ans{0};
	int val = 0;
	for(int i = N - 1; i >= 1; i--){
		val++; // 頂点iを追加
		for(auto j: G[i]){
			if(i < j && !uf.same(i, j)) uf.merge(i, j), val--; // 連結成分が1つ減る
		}
		ans.push_back(val);
	}

	reverse(ans.begin(), ans.end());
	for(int i = 0; i < N; i++) cout << ans[i] << endl;
}