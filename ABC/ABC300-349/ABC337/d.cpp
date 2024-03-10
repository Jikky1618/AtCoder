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
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // 二次元累積和 (., o, x)
    vector acc(3, vector(H + 1, vector(W + 1, 0)));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            acc[0][i + 1][j + 1] = acc[0][i][j + 1] + acc[0][i + 1][j] - acc[0][i][j] + (S[i][j] == '.');
            acc[1][i + 1][j + 1] = acc[1][i][j + 1] + acc[1][i + 1][j] - acc[1][i][j] + (S[i][j] == 'o');
            acc[2][i + 1][j + 1] = acc[2][i][j + 1] + acc[2][i + 1][j] - acc[2][i][j] + (S[i][j] == 'x');
        }
    }

    debug(acc[0]);

    int ans = INF;
    // 行を全探索
    for(int i = 0; i < H; i++){
        // [i, i + 1)[j, j + K) を全探索
        for(int j = 0; j < W - K + 1; j++){
            // x が 1 つ以上あれば continue
            if(acc[2][i + 1][j + K] - acc[2][i][j + K] - acc[2][i + 1][j] + acc[2][i][j] > 0) continue;
            // . の数を数える
            int cnt = acc[0][i + 1][j + K] - acc[0][i][j + K] - acc[0][i + 1][j] + acc[0][i][j];
            ans = min(ans, cnt);
        }
    }
    // 列を全探索
    for(int j = 0; j < W; j++){
        // [i, i + K)[j, j + 1) を全探索
        for(int i = 0; i < H - K + 1; i++){
            // x が 1 つ以上あれば continue
            if(acc[2][i + K][j + 1] - acc[2][i][j + 1] - acc[2][i + K][j] + acc[2][i][j] > 0) continue;
            // . の数を数える
            int cnt = acc[0][i + K][j + 1] - acc[0][i][j + 1] - acc[0][i + K][j] + acc[0][i][j];
            ans = min(ans, cnt);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}