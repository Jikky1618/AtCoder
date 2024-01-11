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
    vector<int> T(N), X(N);
    for(int i = 0; i < N; i++) cin >> T[i] >> X[i];

    vector<vector<ll>> A(3);
    for(int i = 0; i < N; i++) A[T[i]].emplace_back(X[i]);
    for(int i = 0; i < 3; i++) sort(A[i].begin(), A[i].end(), greater<ll>());

    // 累積和
    vector<vector<ll>> S(3);
    for(int i = 0; i < 3; i++){
        int n = A[i].size();
        S[i].resize(n + 1);
        for(int j = 0; j < n; j++) S[i][j + 1] = S[i][j] + A[i][j];
    }

    // T[i] = 1 の個数を全探索
    ll ans = 0;
    for(int i = 0; i <= int(A[1].size()); i++){
        // i 個選ぶときに必要な缶切り
        int need = lower_bound(S[2].begin(), S[2].end(), i) - S[2].begin();
        if(need > int(A[2].size()) || i + need > M) break;
        // T[i] = 0 の個数を求める
        int j = min(M - i - need, int(A[0].size()));
        ans = max(ans, S[1][i] + S[0][j]);
    }

    cout << ans << endl;
}