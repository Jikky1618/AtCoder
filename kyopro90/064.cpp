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
    
    // 階差数列(frontとbackに番兵)
    vector<ll> B(N + 1);
    B.front() = 0;
    for(int i = 0; i < N - 1; i++) B[i + 1] = A[i + 1] - A[i];
    B.back() = 0;

    // 現状の不便さを計算
    ll ans = 0;
    for(auto &&b: B) ans += abs(b);

    while(Q--){
        int L, R, V; cin >> L >> R >> V, L--;
        // 階差数列の影響のある項の変化前
        ll before = abs(B[L]) + abs(B[R]);
        if(0 < L) B[L] += V;
        if(R < N) B[R] -= V;
        // 階差数列の影響のある項の変化後
        ll after = abs(B[L]) + abs(B[R]);

        ans += after - before;
        cout << ans << '\n';
    }
}