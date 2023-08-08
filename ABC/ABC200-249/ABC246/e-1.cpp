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

const vector<int> dx = {1, 1, -1, -1};
const vector<int> dy = {1, -1, -1, 1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, Ax, Ay, Bx, By;
    cin >> N >> Ax >> Ay >> Bx >> By, Ax--, Ay--, Bx--, By--;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    // dist[dir][i][j] := (i, j) に 方向 dir で到達する最短距離
    vector dist(4, vector(N, vector<int>(N, INF)));
    // {x, y, dir} で 01-BFS
    deque<tuple<int, int, int>> que;

    for(int k = 0; k < 4; k++){
        dist[k][Ax][Ay] = 1;
        que.emplace_back(Ax, Ay, k);
    }

    while(!que.empty()){
        auto [x, y, dir] = que.front();
        que.pop_front();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
            if(S[nx][ny] == '#') continue;
            // 前回と同じ方向の場合
            if(k == dir){
                if(dist[k][nx][ny] > dist[dir][x][y]){
                    dist[k][nx][ny] = dist[dir][x][y];
                    que.emplace_front(nx, ny, k);
                }
            // 前回と違う方向の場合
            }else{
                if(dist[k][nx][ny] > dist[dir][x][y] + 1){
                    dist[k][nx][ny] = dist[dir][x][y] + 1;
                    que.emplace_back(nx, ny, k);
                }
            }
        }
    }

    int ans = INF;
    for(int k = 0; k < 4; k++) ans = min(ans, dist[k][Bx][By]);
    
    cout << (ans == INF ? -1 : ans) << endl;
}