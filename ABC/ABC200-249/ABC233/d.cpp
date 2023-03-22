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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    map<ll, ll> cnt;

    ll ans = 0;
    for(int i = 0; i <= N; i++){
        ans += cnt[S[i] - K];
        cnt[S[i]]++;
    }

    cout << ans << endl;
}