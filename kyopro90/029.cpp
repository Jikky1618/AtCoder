#include <bits/stdc++.h>
#include <atcoder/lazysegtree>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int op(int a, int b){
    return max(a, b);
}
int e(){
    return 0;
}
int mapping(int f, int g){
    return (f == 0 ? g : f);
}
int composition(int f, int g){
    return (f == 0 ? g : f);
}
int id(){
    return 0;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int W, N;
    cin >> W >> N;
    
    atcoder::lazy_segtree<int, op, e, int, mapping, composition, id> seg(W);
    for(int i = 0; i < N; i++){
        int L, R; cin >> L >> R, L--;
        int h = seg.prod(L, R) + 1;
        seg.apply(L, R, h);

        cout << h << "\n";
    }
}