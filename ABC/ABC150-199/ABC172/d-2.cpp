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
    int N; cin >> N;

    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ans += i * (N / i) * (1 + (N / i)) / 2;
    }

    cout << ans << endl;
}