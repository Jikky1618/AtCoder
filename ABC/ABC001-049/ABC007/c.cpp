#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;
const vector<int> dx = {0,1,0,-1};
const vector<int> dy = {1,0,-1,0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // 入力
    int r,c,sy,sx,gy,gx;
    cin >> r >> c >> sy >> sx >> gy >> gx;
    sy--, sx--, gy--, gx--;
    vector<string> grid(r);
    for(int i = 0; i < r; i++) cin >> grid[i];

    vector<vector<int>> dist(r,vector<int>(c, INF));
    queue<pair<int, int>> que;

    dist[sy][sx] = 0;
    que.push(pair<int, int>(sy, sx));

    while(!que.empty()){
        pair<int, int> pos = que.front(); que.pop();
        // もしゴール到着したらbreak
        if(pos.first == gy && pos.second == gx) break;
        for(int i = 0; i < 4; i++){
            int ny = pos.first + dy[i];
            int nx = pos.second + dx[i];
            if(nx < 0 || nx >= c || ny < 0 || ny >= r) continue;
            if(dist[ny][nx] != INF) continue;
            if(grid[ny][nx] == '#') continue;
            dist[ny][nx] = dist[pos.first][pos.second] + 1;
            que.push(pair<int, int>(ny, nx));
        } 
    }

    cout << dist[gy][gx] << endl;
    return 0;
}