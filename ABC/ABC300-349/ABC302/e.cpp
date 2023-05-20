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
    int N, Q;
    cin >> N >> Q;

    vector<set<int>> G(N);
    int ans = N;
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int u, v; cin >> u >> v, u--, v--;
            if(G[u].size() == 0) ans--;
            if(G[v].size() == 0) ans--;
            G[u].insert(v);
            G[v].insert(u);
        }
        if(t == 2){
            int v; cin >> v, v--;
            for(auto u: G[v]){
                G[u].erase(v);
                if(G[u].size() == 0) ans++;
            }
            if(G[v].size() != 0) ans++;
            G[v].clear();
        }

        cout << ans << "\n";
    }
}