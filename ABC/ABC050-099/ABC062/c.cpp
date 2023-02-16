#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

template<class T, class U>
T floor(T x, U y){
    return (x ? x / y : (x + y - 1) / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll H, W;
    cin >> H >> W;

    ll ans = INF;
    // 縦に3つ分ける
    ans = min(ans, ceil(H, 3) * W - floor(H, 3) * W);
    // 横に3つ分ける
    ans = min(ans, ceil(W, 3) * H - floor(W, 3) * H);

    // 縦に1回、横に2つに分ける
    for(int i = 0; i < H; i++){
        ll val1 = i * W;
        ll val2 = (H - i) * ceil(W, 2);
        ll val3 = (H - i) * floor(W, 2);
        ans = min(ans, max({val1, val2, val3}) - min({val1, val2, val3}));
    }

    // 横に1回、縦に2つに分ける
    for(int i = 0; i < W; i++){
        ll val1 = i * H;
        ll val2 = (W - i) * ceil(H, 2);
        ll val3 = (W - i) * floor(H, 2);
        ans = min(ans, max({val1, val2, val3}) - min({val1, val2, val3}));
    }

    cout << ans << endl;
}