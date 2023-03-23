#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    ll N, L, R;
    cin >> N >> L >> R;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];


    // lmin[i] := 位置iより左側をLに置き換えた後の総和の最小値
    vector<ll> lmin(N + 1);
    for(int i = 0; i < N; i++) lmin[i + 1] = min(lmin[i] + A[i], L * (i + 1));

    // rmin[i] := 位置iより右側をRに置き換えた後の総和の最小値
    vector<ll> rmin(N + 1);
    for(int i = N - 1; i >= 0; i--) rmin[i] = min(rmin[i + 1] + A[i], R * (N - i));

    ll ans = INF;
    // 位置iを全探索
    for(int i = 0; i <= N; i++) ans = min(ans, lmin[i] + rmin[i]);

    cout << ans << endl;
}