#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    // {sx, sy} := スタート, {gx, gy} := ゴール
    int sx = -1, sy = -1, gx = -1, gy = -1;
    // ワープの場所
    vector<vector<pair<int, int>>> tp(26);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == 'S') sx = i, sy = j;
            if(A[i][j] == 'G') gx = i, gy = j;
            if('a' <= A[i][j] && A[i][j] <= 'z'){
                tp[A[i][j] - 'a'].emplace_back(i, j);
            }
        }
    }

    vector<int> used(26); // ワープを使ったかどうか
    vector dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;

    dist[sx][sy] = 0;
    que.emplace(sx, sy);

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();

        // 4方向に移動
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(A[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            que.emplace(nx, ny);
        }

        // ワープを使う場合
        if('a' <= A[x][y] && A[x][y] <= 'z'){
            char c = A[x][y] - 'a';
            if(used[c]) continue;
            used[c] = true;
            for(auto [nx, ny]: tp[c]){
                if(dist[nx][ny] != -1) continue;
                dist[nx][ny] = dist[x][y] + 1;
                que.emplace(nx, ny);
            }
        }
    }
    cout << dist[gx][gy] << endl; 
}