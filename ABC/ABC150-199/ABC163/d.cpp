#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MOD = 1e9 + 7;


int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, K;
    cin >> N >> K;

    ll ans = 0;
    for(ll i = K; i <= N + 1; i++){
        ll Min = i * (i - 1) / 2;
        ll Max = i * (2 * N - i + 1) / 2;
        ans += Max - Min + 1;
        ans %= MOD;
    }

    cout << ans << endl;
}