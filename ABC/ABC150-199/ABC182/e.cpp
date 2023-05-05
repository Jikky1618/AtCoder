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
    int H, W, N, M;
    cin >> H >> W >> N >> M;
    vector<pair<int, int>> L(N);
    for(int i = 0; i < N; i++){
        int A, B; cin >> A >> B, A--, B--;
        L[i] = {A, B};
    }
    vector B(H, vector<int>(W));
    for(int i = 0; i < M; i++){
        int C, D; cin >> C >> D, C--, D--;
        B[C][D] = true;
    }

    // G[i][j] := {i, j}に横方向の光が届いてるか
    // G2[i][j] := {i, j}に縦方向の光が届いてるか
    vector G(H, vector<int>(W));
    vector G2(H, vector<int>(W));
    for(int i = 0; i < N; i++){
        auto [x, y] = L[i];
        G[x][y] = G2[x][y] = true;
        // 右方向に光
        for(int nx = x + 1; nx < H; nx++){
            if(G[nx][y] || B[nx][y]) break;
            G[nx][y] = true;
        }
        // 左方向に光
        for(int nx = x - 1; nx >= 0; nx--){
            if(G[nx][y] || B[nx][y]) break;
            G[nx][y] = true;
        }
        // 下方向に光
        for(int ny = y + 1; ny < W; ny++){
            if(G2[x][ny] || B[x][ny]) break;
            G2[x][ny] = true;
        }
        // 上方向に光
        for(int ny = y - 1; ny >= 0; ny--){
            if(G2[x][ny] || B[x][ny]) break;
            G2[x][ny] = true;
        }
    }

    int ans = 0;
    debug(G, G2);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(G[i][j] || G2[i][j]) ans++;
        }
    }

    cout << ans << endl;
}