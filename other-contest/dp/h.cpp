#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;
const vector<int> dx = {0, 1};
const vector<int> dy = {1, 0};

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

    // dp[i][j] := (i, j) にたどり着く経路数
    vector dp(H, vector<ll>(W));
    dp[0][0] = 1;

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            // 右, 下に移動する
            for(int k = 0; k < 2; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(nx >= H || ny >= W) continue;
                if(A[nx][ny] == '#') continue;
                dp[nx][ny] += dp[i][j];
                dp[nx][ny] %= MOD;
            }
        }
    }

    cout << dp[H - 1][W - 1] << endl;
}