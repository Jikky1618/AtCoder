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
    int H, W, D;
    cin >> H >> W >> D;
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j], A[i][j]--;
    }
    int Q;
    cin >> Q;

    // 各数字の座標を記録
    vector<pair<int, int>> P(H * W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            P[A[i][j]] = make_pair(i, j);
        }
    }

    // D が固定なので、 x -> x + D にいくためのコストを前計算
    vector dist(H, vector<int>(W, -1));
    for(int x = 0; x < H; x++){
        for(int y = 0; y < W; y++){
            int np = A[x][y] + D; // np := 次の数字
            if(H * W < np) continue;

            auto [nx, ny] = P[np]; // (nx, ny) := 次の数字の座標
            dist[x][y] = abs(nx - x) + abs(ny - y);
        }
    }
    debug(dist);

    // mod D ごとに累積和を計算
    vector S(D, vector<int>(H * W / D + 1));
    for(int i = 0; i < D; i++){
        for(int j = 0; j < H * W / D; j++){
            auto [x, y] = P[i + D * j];
            S[i][j + 1] = S[i][j] + dist[x][y];
        }
    }

    while(Q--){
        int L, R; cin >> L >> R, L--, R--;
        int mod = L % D;
        int l = L / D, r = R / D;
        cout << S[mod][r] - S[mod][l] << '\n';
    }
}