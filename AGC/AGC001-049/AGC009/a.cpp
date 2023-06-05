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
    int N;
    cin >> N;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    ll ans = 0;
    // 末尾から必要な回数を見ていく
    for(int i = N - 1; i >= 0; i--){
        // すでに A[i] が B[i] の倍数ならcontinue
        if((A[i] + ans) % B[i] == 0) continue;
        ans += B[i] - ((A[i] + ans) % B[i]);
    }

    cout << ans << endl;
}