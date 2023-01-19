#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

const vector<int> dx = {0,1,0,-1};
const vector<int> dy = {1,0,-1,0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    vector<vector<int>> dist(H, vector<int>(W, INF));
    queue<pair<int, int>> que;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == '#'){
                que.push({i, j});
                dist[i][j] = 0;
            }
        }
    }

    while(!que.empty()){
        auto pos = que.front(); que.pop();
        for(int i = 0; i < 4; i++){
            int nx = pos.first + dx[i];
            int ny = pos.second + dy[i];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(dist[nx][ny] != INF) continue;
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
}