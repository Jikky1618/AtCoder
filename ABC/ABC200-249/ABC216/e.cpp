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
    int N, K;
    cin >> N >> K;
    vector<ll> A(N + 1);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end(), greater<ll>());

    ll ans = 0;
    for(int i = 0; i < N; i++){
        debug(ans);
        ll diff = A[i] - A[i + 1];
        ll cnt = (i + 1) * diff;
        if(cnt <= K){
            ans += (i + 1) * diff * (A[i] + (A[i] - diff + 1)) / 2;
            K -= cnt;
        }else{
            ll cnt1 = K / (i + 1);
            ll cnt2 = K % (i + 1);
            ans += (i + 1) * cnt1  * (A[i] + (A[i] - cnt1 + 1)) / 2;
            ans += (A[i] - cnt1) * cnt2;
            break;
        }
    }

    cout << ans << endl;
}