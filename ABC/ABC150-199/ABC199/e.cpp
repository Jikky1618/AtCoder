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
    vector<int> X(M), Y(M), Z(M);
    for(int i = 0; i < M; i++) cin >> X[i] >> Y[i] >> Z[i], Y[i]--;

    // dp[S](S :={1, ..., N}の部分集合S) := aの|S|要素まで決めていて、X[i] <= |S| の条件を全て満たしている場合の数
    vector<ll> dp(1 << N);
    dp[0] = 1;

    // bitDP
    for(int bit = 0; bit < (1 << N); bit++){
        // 次の要素nxを全探索
        for(int nx = 0; nx < N; nx++){
            // nxが既にSの要素ならcontinue
            if((bit >> nx) & 1) continue;

            // 新しい部分集合Sを構築
            vector<int> S = {nx};
            for(int i = 0; i < N; i++){
                if((bit >> i) & 1) S.emplace_back(i);
            }

            // X[i] = |S|の条件を全て満たすかを確認(X[i] < |S|の条件は満たしている)
            bool flag = true;
            for(int i = 0; i < M; i++){
                // X[i] != |S|ならcontinue
                if(X[i] != S.size()) continue;
                // Y[i]以下の要素の数がZ[i]個以下か判定する
                int cnt = 0;
                for(auto &&s: S){
                    if(s <= Y[i]) cnt++;
                }
                if(cnt > Z[i]) flag = false;
            }

            // 遷移
            if(flag) dp[bit | (1 << nx)] += dp[bit];
        }
    }

    cout << dp[(1 << N) - 1] << endl;
}