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
    vector dist(N, vector<int>(N, INF));
    queue<tuple<int, int>> que;

    dist[Ax][Ay] = 0;
    que.emplace(Ax, Ay);

    while(!que.empty()){
        auto [x, y] = que.front();
        que.pop();
        for(int k = 0; k < 4; k++){
            int nx = x, ny = y;
            // 枝刈り BFS
            while(true){
                nx += dx[k], ny += dy[k];
                if(nx < 0 || nx >= N || ny < 0 || ny >= N) break;
                if(S[nx][ny] == '#') break;
                
                // これで枝刈り
                if(dist[nx][ny] < dist[x][y] + 1) break;

                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    que.emplace(nx, ny);
                }
            }
        }
    }

    debug(dist);
    cout << (dist[Bx][By] == INF ? -1 : dist[Bx][By]) << endl;
}