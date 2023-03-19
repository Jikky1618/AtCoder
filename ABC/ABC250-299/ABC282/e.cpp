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

template<class T>
T mod_pow(T base, T exp, T mod){
    T res = 1;
    base %= mod;
    while(exp > 0){
        if(exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 重さが (x^y+y^x)%M の辺を構築する
    vector<tuple<int, int, ll>> G;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == j) continue;
            ll cost = (mod_pow(A[i], A[j], M) + mod_pow(A[j], A[i], M)) % M;
            G.push_back({cost, i, j});
        }
    }

    sort(G.begin(), G.end(), greater<tuple<ll, int, int>>());

    ll ans = 0;
    // クラスカル法
    UnionFind uf(N);
    for(auto [cost, from, to]: G){
        if(!uf.same(from, to)){
            uf.merge(from, to);
            ans += cost;
        }
    }

    cout << ans << endl;
}