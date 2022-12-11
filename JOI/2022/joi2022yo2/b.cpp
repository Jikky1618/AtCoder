#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const vector<int> dx = {0,1,0,-1};
const vector<int> dy = {1,0,-1,0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // dist := スタート位置からの各頂点の距離(初期化-1)
    vector dist(H, vector<int>(W, -1));
    // que := 発見したが未到達の頂点を格納
    queue<pair<int, int>> que;

    dist[0][0] = 0;
    que.push({0, 0});
    while(!que.empty()){
        auto pos = que.front(); que.pop();
        if(pos.first == H-1 && pos.second == W-1) break; // 右下に到着
        for(int i = 0; i < 4; i++){
            int ny = pos.first + dy[i];
            int nx = pos.second + dx[i];
            if(nx < 0 || nx >= W || ny < 0 || ny >= H) continue;
            if(dist[ny][nx] != -1) continue;
            if(S[pos.first][pos.second] == S[ny][nx]) continue;
            dist[ny][nx] = dist[pos.first][pos.second] + 1;
            que.push({ny, nx});
        }
    }

    // for(auto i: dist){
    //     for(auto j: i){
    //         cout << j << " ";
    //     }
    //     cout << endl;
    // }

    cout << dist[H-1][W-1] << endl;

    return 0;
}