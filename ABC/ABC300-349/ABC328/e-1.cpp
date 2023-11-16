#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class T>
bool next_combination(const T first, const T last, int k) {
    const T subset = first + k;
    // empty container
    if(first == last || first == subset || last == subset) {
        return false;
    }
    T src = subset;
    while(first != src) {
        src--;
        if(*src < *(last - 1)) {
            T dest = subset;
            while(*src >= *dest) {
                dest++;
            }
            iter_swap(src, dest);
            rotate(src + 1, dest + 1, last);
            rotate(subset, subset + (last - dest) - 1, last);
            return true;
        }
    }
    // restore
    rotate(first, subset, last);
    return false;
}

struct UnionFind {
     // n := 要素数, group_size := 連結成分の個数
    int n, group_size;
    // parent_or_size[i] := iの親要素
    // parent_or_size[i] * -1 :=  iの属する連結成分の頂点数
    vector<int> parent_or_size;

    // 構造体の初期化
    UnionFind(int size): n(size), group_size(size), parent_or_size(size, -1) {}

    // root(x): 要素xの根を返す(xが根の場合xを返す)
    int root(int x){
        return (parent_or_size[x] < 0 ? x : parent_or_size[x] = root(parent_or_size[x]));
    }

    // same(x, y): xとyが同じ連結成分に属するかを返す (= 根が一致するか)
    bool same(int x, int y){
        return root(x) == root(y);
    }

    // merge(x, y): 要素x, yを併合する
    bool merge(int x, int y){
        int rx = root(x), ry = root(y);
        if(rx == ry) return false;
        if(-parent_or_size[rx] < -parent_or_size[ry]) swap(rx, ry); 
        parent_or_size[rx] += parent_or_size[ry]; 
        parent_or_size[ry] = rx;
        group_size--;
        return true;
    }

    // size(x): 要素xの連結成分の大きさを返す
    int size(int x){
        return -parent_or_size[root(x)];
    }

    // group_count(): 連結成分の個数を返す
    int group_count(){
        return group_size;
    }

    // group(x): 要素xの連結成分を1次元配列で返す
    vector<int> group(int x){
        vector<int> res;
        for(int i = 0; i < n; i++){
            if(same(x, i)) res.emplace_back(i);
        }
        return res;
    }

    // groups(): 連結成分を2次元配列で返す
    vector<vector<int>> groups(){
        vector<vector<int>> res(n);
        for(int i = 0; i < n; i++){
            res[root(i)].emplace_back(i);
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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<tuple<int, int, ll>> edges(M);
    for(int i = 0; i < M; i++){
        int u, v; ll w; cin >> u >> v >> w, u--, v--;
        edges[i] = {u, v, w};
    }
    sort(edges.begin(), edges.end());

    // M 個の頂点から N - 1 個選ぶ組合せを全探索
    ll ans = K;
    do{
        UnionFind uf(N);
        ll cost = 0;
        bool flag = true; // ちゃんと全域木かどうか判定
        for(int i = 0; i < N - 1; i++){
            auto [u, v, w] = edges[i];
            if(uf.same(u, v)){
                flag = false;
                break;
            }
            uf.merge(u, v);
            cost += w;
            if(cost > K) cost -= K;
        }
        if(flag) ans = min(ans, cost);
    }while(next_combination(edges.begin(), edges.end(), N - 1));

    cout << ans << '\n';
}