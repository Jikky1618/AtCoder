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
    int N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    // dp[i] := Aのi番目からi + M番目の連続部分列の値
    vector<ll> dp(N - M + 1);
    for(int i = 0; i < M; i++) dp[0] += (i + 1) * A[i];
    
    for(int i = 0; i < N - M; i++){
        ll diff = -(S[i + M] - S[i]) + M * A[i + M];
        dp[i + 1] = dp[i] + diff;
    }

    cout << *max_element(dp.begin(), dp.end()) << endl;
}