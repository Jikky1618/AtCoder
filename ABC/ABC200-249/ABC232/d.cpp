#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const vector<int> dx = {0,1};
const vector<int> dy = {1,0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(int i = 0; i < H; i++) cin >> C[i];

    vector dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;

    dist[0][0] = 1;
    que.push({0, 0});

    while(!que.empty()){
        auto pos = que.front(); que.pop();
        
        for(int i = 0; i < 2; i++){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if(nx >= H || ny >= W || C[nx][ny] == '#') continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[pos.first][pos.second] + 1;
            que.push({nx, ny});
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            ans = max(ans, dist[i][j]);
        }
    }

    cout << ans << endl;
    return 0;
}