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
    int N, C;
    cin >> N >> C;
    vector D(C, vector<int>(C));
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++) cin >> D[i][j];
    }
    vector c(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> c[i][j], c[i][j]--;
    }

    // (i + j) mod 3 の色の個数を数える
    vector cnt(3, vector<int>(C));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            cnt[(i + j + 2) % 3][c[i][j]]++;
        }
    }

    debug(cnt);
    int ans = INF;
    // 3 グループの塗る色を固定
    for(int i = 0; i < C; i++){
        for(int j = 0; j < C; j++){
            if(i == j) continue;
            for(int k = 0; k < C; k++){
                if(i == k || j == k) continue;
                int val = 0;
                // コストを計算
                for(int l = 0; l < C; l++){
                    val += cnt[0][l] * D[l][i];
                    val += cnt[1][l] * D[l][j];
                    val += cnt[2][l] * D[l][k];
                }
                ans = min(ans, val);
                debug(i, j, k, val);
            }
        }
    }

    cout << ans << endl;
}