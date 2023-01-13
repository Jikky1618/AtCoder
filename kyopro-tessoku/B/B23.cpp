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
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    // dp[S][i] := ：訪問した都市の集合がSであり、現在位置がiであるときの最小移動距離
    vector dp((1 << N), vector<double>(N+1, INF));
    dp[0][0] = 0;

    for(int bit = 0; bit < (1 << N); bit++){
        for(int i = 0; i < N; i++){
            // 未到達ならcontinue
            if(dp[bit][i] >= INF) continue;

            for(int j = 0; j < N; j++){
                // 都市jが既に訪問済みならcontinue
                if((bit >> j) & 1) continue;

                // 都市i, jの距離を計算
                double dist = hypot(X[i] - X[j], Y[i] - Y[j]);

                // DPを更新
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + dist);
            }
        }
    }

    cout << dp[(1 << N) - 1][0] << endl;
}