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
    ll N, K;
    cin >> N >> K;

    // corner case: K = 0
    if(K == 0){
        ll ans = N * N;
        cout << ans << endl;
        return 0;
    }

    ll ans = 0;
    for(int b = K + 1; b <= N; b++){
        ans += (N / b) * (b - K) + max(0LL, N % b - (K - 1));
    }

    cout << ans << endl;
}