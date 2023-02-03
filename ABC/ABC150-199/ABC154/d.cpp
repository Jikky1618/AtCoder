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
    vector<int> p(N);
    for(int i = 0; i < N; i++) cin >> p[i];

    // 期待値の計算
    vector<double> E(N);
    for(int i = 0; i < N; i++) E[i] = (double)(1 + p[i]) / 2;

    vector<double> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + E[i];

    double ans = 0;
    for(int i = K; i < N; i++){
        ans = max(ans, S[i + 1] - S[i - K]);
    }

    cout << ans << endl;
}