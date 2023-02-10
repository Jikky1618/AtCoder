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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    int Q;
    cin >> Q;

    map<ll, ll> cnt;
    for(int i = 0; i < N; i++) cnt[A[i]]++;

    ll ans = 0;
    for(int i = 0; i < N; i++) ans += A[i];

    while(Q--){
        ll B, C; cin >> B >> C;
        ll replace = cnt[B];
        
        // ansの差分更新1
        ans -= replace * B;
        // cnt[B], cnt[C]の差分更新
        cnt[B] = 0, cnt[C] += replace;
        // ansの差分更新2
        ans += replace * C;

        cout << ans << '\n';
    }
}