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
    int N, Q;
    cin >> N >> Q;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end());
    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    while(Q--){
        ll X; cin >> X;
        ll pos = lower_bound(A.begin(), A.end(), X) - A.begin();
        ll ans = (X * pos - S[pos]) + (S[N] - S[pos] - X * (N - pos));
        cout << ans << '\n';
    }
}