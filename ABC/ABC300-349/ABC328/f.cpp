#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// https://github.com/drken1215/algorithm/blob/master/DataStructure/weighted_union_find.cpp
// Weighted Union-Find (T: the type of v[0], v[1], ..., v[N-1])
template<class T> struct WeightedUnionFind {
    // core member
    vector<int> par;
    vector<T> weight;

    // constructor
    WeightedUnionFind() { }
    WeightedUnionFind(int N, T zero = 0) : par(N, -1), weight(N, zero) {}
    void init(int N, T zero = 0) {
        par.assign(N, -1);
        weight.assign(N, zero);
    }
    
    // core methods
    int root(int x) {
        if (par[x] < 0) return x;
        else {
            int r = root(par[x]);
            weight[x] += weight[par[x]];
            return par[x] = r;
        }
    }
    bool same(int x, int y) {
        return root(x) == root(y);
    }
    int size(int x) {
        return -par[root(x)];
    }
    
    // v[y] - v[x] = w
    bool merge(int x, int y, T w) {
        w += get_weight(x), w -= get_weight(y);
        x = root(x), y = root(y);
        if (x == y) return false;
        if (par[x] > par[y]) swap(x, y), w = -w; // merge technique
        par[x] += par[y];
        par[y] = x;
        weight[y] = w;
        return true;
    }
    
    // get v[x]
    T get_weight(int x) {
        root(x);
        return weight[x];
    }
    
    // get v[y] - v[x]
    T get_diff(int x, int y) {
        return get_weight(y) - get_weight(x);
    }
    
    // get groups
    vector<vector<int>> groups() {
        vector<vector<int>> member(par.size());
        for (int v = 0; v < (int)par.size(); ++v) {
            member[root(v)].push_back(v);
        }
        vector<vector<int>> res;
        for (int v = 0; v < (int)par.size(); ++v) {
            if (!member[v].empty()) res.push_back(member[v]);
        }
        return res;
    }
    
    // debug
    friend ostream& operator << (ostream &s, WeightedUnionFind uf) {
        const vector<vector<int>> &gs = uf.groups();
        for (const vector<int> &g : gs) {
            s << "group: ";
            for (int v : g) s << v << "(" << uf.get_weight(v) << ") ";
            s << endl;
        }
        return s;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;
    
    WeightedUnionFind<ll> uf(N);
    vector<int> ans;
    for(int i = 0; i < Q; i++){
        int a, b, d;
        cin >> a >> b >> d, a--, b--;
        if(uf.same(a, b)){
            debug(i, uf.get_diff(a, b));
            if(uf.get_diff(a, b) == d) ans.emplace_back(i + 1);
        }else{
            uf.merge(a, b, d);
            ans.emplace_back(i + 1);
        }
    }

    debug(ans);
    for(unsigned i = 0; i < ans.size(); i++) cout << ans[i] << " \n"[i + 1 == ans.size()];
}