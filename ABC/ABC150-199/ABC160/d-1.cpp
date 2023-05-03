#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);
	int N, X, Y;
	cin >> N >> X >> Y, X--, Y--;

	vector<vector<int>> G(N);
	for(int i = 0; i < N - 1; i++){
		G[i].emplace_back(i + 1);
		G[i + 1].emplace_back(i);
	}
	G[X].emplace_back(Y), G[Y].emplace_back(X);
	debug(G);

	vector<int> ans(N);
	for(int i = 0; i < N; i++){
		vector<int> dist(N, -1);
		queue<int> que;

		dist[i] = 0;
		que.push(i);
		while(!que.empty()){
			int pos  = que.front(); que.pop();
			for(auto np: G[pos]){
				if(dist[np] != -1) continue;
				dist[np] = dist[pos] + 1;
				que.push(np);
			}
		}
		for(int k = 0; k < i; k++) ans[dist[k]]++;
	}

	for(int k = 1; k < N; k++){
		cout << ans[k] << "\n";
	}
}