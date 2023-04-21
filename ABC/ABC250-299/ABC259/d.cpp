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

ll pow(ll a, int n){
    ll res = 1;
    while (n > 0){
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    ll sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;
    vector<ll> x(N), y(N), r(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i] >> r[i];

    // sx, syとtx, tyがどの円上にあるのかを判定
    int s = -1, t = -1;
    for(int i = 0; i < N; i++){
        ll dist1 = pow(x[i] - sx, 2) + pow(y[i] - sy, 2);
        ll dist2 = pow(x[i] - tx, 2) + pow(y[i] - ty, 2);
        if(r[i] * r[i] == dist1) s = i;
        if(r[i] * r[i] == dist2) t = i;
    }

    UnionFind uf(N);
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            ll dist = pow(abs(x[i] - x[j]), 2) + pow(abs(y[i] - y[j]), 2);
            if(pow(r[i] - r[j], 2) <= dist && dist <= pow(r[i] + r[j], 2)){
                uf.merge(i, j);
            }
        }
    }

    cout << (uf.same(s, t) ? "Yes" : "No") << endl;
}