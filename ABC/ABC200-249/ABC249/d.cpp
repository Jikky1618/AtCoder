#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MAX = 2e5;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    vector<ll> cnt(MAX + 1);
    for(int i = 0; i < N; i++) cnt[A[i]]++;

    ll ans = 0;
    for(int Aj = 1; Aj <= MAX; Aj++){
        for(int Ak = 1; Ak <= MAX / Aj; Ak++){
            ll Ai = Aj * Ak;
            ans += cnt[Ai] * cnt[Aj] * cnt[Ak];
        }
    }

    cout << ans << endl;
}