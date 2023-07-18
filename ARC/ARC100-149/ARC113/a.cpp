#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll K;
    cin >> K;
    
    ll ans = 0;
    // 打ち切り全探索
    for(ll A = 1; A <= K; A++){
        for(ll B = 1; A * B <= K; B++){
            for(ll C = 1; A * B * C <= K; C++){
                ans++;
            }
        }
    }

    cout << ans << endl;
}