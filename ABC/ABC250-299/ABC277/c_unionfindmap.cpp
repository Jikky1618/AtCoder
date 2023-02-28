#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T>
struct UnionFindMap {
    int n; // 連結成分の個数
    // parent[i] := iの親要素, sizes[i] := iの属する連結成分の頂点数
    unordered_map<T, T> parent;
    unordered_map<T, int> sizes;

    // 構造体の初期化
    UnionFindMap(): n(0) {}

    // 要素xを挿入する
    void insert(T x){
        if(parent.count(x)) return;
        parent[x] = x;
        sizes[x] = 1;
        n++;
    }

    // root(x): 要素xの根を返す(xが根の場合xを返す)
    T root(T x){
        insert(x);
        return (sizes.count(x) ? x : parent[x] = root(parent[x]));
    }

    // same(x, y): xとyが同じ連結成分に属するかを返す (= 根が一致するか)
    bool same(T x, T y){
        return root(x) == root(y);
    }

    // merge(x, y): 要素x, yを併合する
    bool merge(T x, T y){
        T rx = root(x), ry = root(y);
        if(rx == ry) return false;
        if(sizes[rx] > sizes[ry]) swap(rx, ry); 
        sizes[rx] += sizes[ry];
        sizes.erase(ry);
        parent[ry] = rx;
        n--; // 連結成分の数を1つ減らす
        return true;
    }
    
	// size(x): 要素xの連結成分の大きさを返す
    int size(T x){
        return sizes[root(x)];
    }

    // size: 連結成分の個数を返す
    int size(){
        return n;
    }

    // group(x) : 要素xの連結成分を1次元配列で返す
    vector<T> group(T x){
        vector<T> res;
        for(auto e: parent){
            if(same(x, e.first)) res.push_back(e.first);
        }
        return res;
    }

    // groups(): 連結成分を2次元配列で返す
    vector<vector<T>> groups(){
        vector<vector<T>> res(n);
        unordered_map<T, int> tmp; int i = 0;
        for(auto e: sizes) tmp[e.first] = i++;
        for(auto e: parent){
            T x = root(e.first);
            res[tmp[x]].push_back(e.first);
        }
        return res;
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    UnionFindMap<ll> uf;
    for(int i = 0; i < N; i++){
        ll A, B; cin >> A >> B;
        uf.merge(A, B);
    }

    auto G = uf.group(1);
    cout << (G.empty() ? 1 : *max_element(G.begin(), G.end())) << endl;
}