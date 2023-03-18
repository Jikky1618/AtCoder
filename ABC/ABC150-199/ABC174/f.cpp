#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class Abel>
struct BinaryIndexedTree {
    int n;
    vector<Abel> dat;
    Abel UNITY_SUM = 0;

    BinaryIndexedTree(int size, Abel unity = 0): n(size + 1), dat(size + 1, unity), UNITY_SUM(unity) {}

    // val[a] += x
    // a is 1-indexed
    void add(int a, Abel x){
        for(int i = a; i <= n; i += i & -i){
            dat[i] += x;
        }
    }

    // val[1] + ... + val[a]
    Abel sum(int a){
        Abel res = UNITY_SUM;
        for(int i = a; i > 0; i -= i & -i){
            res += dat[i];
        }
        return res;
    }

    Abel sum(int a, int b){
        return sum(b) - sum(a);
    }

    Abel all(){
        return dat.front();
    }
};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Q;
    cin >> N >> Q;
    vector<int> c(N);
    for(int i = 0; i < N; i++) cin >> c[i];

     // クエリ先読み
    vector<vector<pair<int, int>>> query(N);
    for(int i = 0; i < Q; i++){
        int l, r; cin >> l >> r, l--, r--;
        query[l].push_back({r, i});
    }

    vector<int> last(N + 1, -1); // last[i] := iが最後に登場したのは何番目か
    vector<vector<int>> p(N);
    for(int i = 0; i < N; i++){
        int l = last[c[i]];
        if(l != -1) p[l].push_back(i);
        last[c[i]] = i;
    }

    vector<int> ans(Q);
    BinaryIndexedTree<int> bit(N);
    for(int x = N - 1; x >= 0; x--){
        for(auto y: p[x]) bit.add(y, 1);
        for(auto [r, id]: query[x]){
            ans[id] = (r - x + 1) - bit.sum(r);
        }
    }

    for(int i = 0; i < Q; i++){
        cout << ans[i] << '\n';
    }
}