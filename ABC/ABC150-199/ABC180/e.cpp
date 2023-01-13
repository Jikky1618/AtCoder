#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> X(N), Y(N), Z(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i] >> Z[i];

    // dp[S][i] := 訪問した都市の集合がSであり、現在位置がiであるときの最小コスト
    vector dp((1 << N), vector<int>(N+1, INF));
    dp[0][0] = 0;

    for(int bit = 0; bit < (1 << N); bit++){
        for(int i = 0; i < N; i++){
            // 未到達ならcontinue
            if(dp[bit][i] == INF) continue;

            // 都市iからjへ移動
            for(int j = 0; j < N; j++){
                // 既に都市jを訪問済みならcontinue
                if((bit >> j) & 1) continue;
                // 都市i, jのコストを計算
                int cost = abs(X[j] - X[i]) + abs(Y[j] - Y[i]) + max(0, Z[j] - Z[i]);
                // dpを更新
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + cost);
            }
        }
    }

    cout << dp[(1 << N) - 1][0] << endl;
}