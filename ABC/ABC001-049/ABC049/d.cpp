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
    int N, K, L;
    cin >> N >> K >> L;

    UnionFind uf1(N);
    for(int i = 0; i < K; i++){
        int p, q; cin >> p >> q, p--, q--;
        uf1.merge(p, q);
    }

    UnionFind uf2(N);
    for(int i = 0; i < L; i++){
        int r, s; cin >> r >> s, r--, s--;
        uf2.merge(r, s);
    }

    // uf1, uf2の都市iの根のペアを管理
    map<pair<int, int>, int> mp;
    for(int i = 0; i < N; i++){
        int root_road = uf1.root(i), root_train = uf2.root(i);
        mp[{root_road, root_train}]++;
    }

    // uf1, uf2の根のペアの頻度を答える
    for(int i = 0; i < N; i++){
        int root_road = uf1.root(i), root_train = uf2.root(i);
        int ans = mp[{root_road, root_train}];
        cout << ans << " \n"[i == N - 1];
    }
}