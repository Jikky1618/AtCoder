#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    // dp[i] := 都市1から進んで都市iに行くまでに通るテレポーターの数の最小値
    // ep[i] := 都市iから進んで都市Nに行くまでに通るテレポーターの数の最小値
    vector<int> dp(N, INF), ep(N, INF);

    dp[0] = ep[N - 1] = 0; // 0-indexed
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            if(S[i][j] == '1') dp[i + j + 1] = min(dp[i + j + 1], dp[i] + 1);
        }
    }
    for(int i = N - 1; i >= 0; i--){
        for(int j = 0; j < M; j++){
            if(S[i][j] == '1') ep[i] = min(ep[i], ep[i + j + 1] + 1);
        }
    }

    // 各kについて求める
    for(int k = 1; k < N - 1; k++){
        int ans = INF;
        // kのM個周辺の点(l, r)にテレポートがあればansを更新する
        for(int l = max(0, k - M); l < k; l++){
            for(int r = k + 1; r <= min(N, k + M); r++){
                if(r - l - 1 >= M) break;
                if(S[l][r - l - 1] == '1') ans = min(ans, dp[l] + ep[r] + 1);
            }
        }
        cout << (ans == INF ? -1 : ans) << " \n"[k == N - 2];
    }
}