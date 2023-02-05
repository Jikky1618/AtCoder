#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    ll x;
    cin >> x;
    // solve 1
    // ll ans = ceil(x, 11) * 2; // 11のセット×2回
    // if(x <= 11 * (ans / 2) - 5) ans--; // 最後の5を振らなくてもokならansを-1

    // solve 2
    int mod = x % 11;
    ll ans = (x / 11) * 2; // 11のセット×2回
    // mod = 0: 追加なし
    // 0 < mod < 7: 6を追加(操作回数+1)
    // 7 <= mod: 6→5を追加(操作回数+2)
    if(0 < mod && mod < 7){
        ans++;
    }else if(7 <= mod){
        ans += 2;
    }

    cout << ans << endl;
}