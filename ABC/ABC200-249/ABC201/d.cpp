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
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    vector p(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            p[i][j] = (A[i][j] == '+' ? 1 : -1);
        }
    }

    // dp[i][j] := マス(i, j)のとき、最善を尽くしたときの (高橋君の得点) - (青木君の得点)
    vector dp(H, vector<int>(W));
    dp[H - 1][W - 1] = 0;

    for(int i = H - 1; i >= 0; i--){
        for(int j = W - 1; j >= 0; j--){
            if(i == H - 1 && j == W - 1) continue;
            // 高橋君のターン: (高橋君の得点) − (青木君の得点) の最大値
            if((i + j) % 2 == 0){
                dp[i][j] = -INF;
                if(i + 1 < H) dp[i][j] = max(dp[i][j], dp[i + 1][j] + p[i + 1][j]);
                if(j + 1 < W) dp[i][j] = max(dp[i][j], dp[i][j + 1] + p[i][j + 1]);
            // 青木くんのターン: (高橋君の得点) - (青木君の得点) の最小値
            }else{
                dp[i][j] = INF;
                if(i + 1 < H) dp[i][j] = min(dp[i][j], dp[i + 1][j] - p[i + 1][j]);
                if(j + 1 < W) dp[i][j] = min(dp[i][j], dp[i][j + 1] - p[i][j + 1]);
            }
        }
    }
    
    if(dp[0][0] > 0){
        cout << "Takahashi" << endl;
    }else if(dp[0][0] < 0){
        cout << "Aoki" << endl;
    }else{
        cout << "Draw" << endl;
    }
}