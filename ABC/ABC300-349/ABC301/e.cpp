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

const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W, T;
    cin >> H >> W >> T;
    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    // s, g, o の地点の{x, y}配列
    vector<pair<int, int>> P;
    int start = -1, goal = -1; // s, g がそれぞれPの何番目にあるかを求める
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == 'o') P.emplace_back(i, j);
            if(A[i][j] == 'S') start = P.size(), P.emplace_back(i, j);
            if(A[i][j] == 'G') goal = P.size(), P.emplace_back(i, j);
        }
    }

    int N = P.size();
    vector d(N, vector<int>(N, INF));
    // 各地点(s, g, o)の距離をbfsで求める
    for(int i = 0; i < N; i++){
        auto [sx, sy] = P[i];
        vector dist(H, vector<int>(W, -1));
        queue<pair<int, int>> que;
        dist[sx][sy] = 0;
        que.emplace(sx, sy);

        while(!que.empty()){
            auto [x, y] = que.front(); que.pop();
            for(int k = 0; k < 4; k++){
                int nx = x + dx[k], ny = y + dy[k];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W || A[nx][ny] == '#') continue;
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                que.emplace(nx, ny);
            }
        }

        for(int j = 0; j < N; j++){
            auto [x, y] = P[j];
            /* !!! このif文を書いてないとd[i][j]の長さが-1になってバグります !!! */
            if(dist[x][y] != -1) d[i][j] = dist[x][y];
        }
    }

    debug(P, start, goal, d);
    // bitDP
    // dp[i][S] := 今まで訪れた地点(s, g, o)の集合をS, 今いる地点をiとしたときの最短距離
    vector dp((1 << N), vector<int>(N, INF));
    dp[1 << start][start] = 0;

    for(int bit = 0; bit < (1 << N); bit++){
        for(int i = 0; i < N; i++){
            if(dp[bit][i] >= INF) continue;
            for(int j = 0; j < N; j++){
                if((bit >> j) & 1) continue;
                dp[bit | (1 << j)][j] = min(dp[bit | (1 << j)][j], dp[bit][i] + d[i][j]);
            }
        }
    }

    int ans = -1;
    for(int bit = 0; bit < (1 << N); bit++){
        if((dp[bit][goal] <= T)) ans = max(ans, __builtin_popcount(bit) - 2);
    }

    cout << ans << endl;
}