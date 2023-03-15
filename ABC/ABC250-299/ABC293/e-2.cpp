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
    ll A, X, M;
    cin >> A >> X >> M;

    
    if(A == 1){
        cout << X % M << endl;
        return 0;
    }

    ll ans = ((mod_pow((__int128_t)A, (__int128_t)X, (__int128_t)M * (A - 1)) - 1) / (A - 1) + M) % M;
    cout << ans << endl;
}