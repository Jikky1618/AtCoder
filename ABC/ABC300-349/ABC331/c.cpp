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

    auto B(A);
    sort(B.begin(), B.end());
    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + B[i];
    debug(B, A);

    vector<ll> ans(N);
    for(int i = 0; i < N; i++){
        int idx = upper_bound(B.begin(), B.end(), A[i]) - B.begin();
        debug(idx);
        ans[i] = S[N] - S[idx];
    }

    for(int i = 0; i < N; i++) cout << ans[i] << " \n"[i == N - 1];
}