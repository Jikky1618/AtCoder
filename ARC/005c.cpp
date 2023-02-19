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

const vector<int> dx = {0,1,0,-1};
const vector<int> dy = {1,0,-1,0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(int i = 0; i < H; i++){
        cin >> C[i];
    }
    int sx, sy, gx, gy;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(C[i][j] == 's') sx = i, sy = j;
            if(C[i][j] == 'g') gx = i, gy = j;
        }
    }

    // 01-BFS
    deque<pair<int, int>> deq;
    vector dist(H, vector<int>(W, INF));

    deq.push_back({sx, sy});
    dist[sx][sy] = 0;

    while(!deq.empty()){
        auto [x, y] = deq.front(); deq.pop_front();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;

            bool wall = (C[nx][ny] == '#');
            if(dist[nx][ny] > dist[x][y] + wall){
                dist[nx][ny] = dist[x][y] + wall;
                if(wall == true) deq.push_back({nx, ny});
                else deq.push_front({nx, ny});
            }
        }
    }

    cout << (dist[gx][gy] <= 2 ? "YES" : "NO") << endl;
}