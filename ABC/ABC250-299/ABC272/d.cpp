#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    // 入力
    int n,m;
    cin >> n >> m;

    // 1操作で行けるマスを列挙
    vector<pair<int,int>> dxy;
    for(int i = -n; i <= n; i++){
        for(int j = -n; j <= n; j++){
            int dist = i * i + j * j;
            if(dist == m){
                dxy.push_back(pair<int,int>(i,j));
            }
        }
    }

    // マス目(INFで初期化)
    vector<vector<int>> dist(n,vector<int>(n, INF));

    queue<pair<int, int>> que;
    // 初期化
    dist[0][0] = 0;
    que.push(pair<int, int>(0, 0));

    // 幅優先探索
    while(!que.empty()){
        // pos := 現在位置(pair<int, int>)
        pair<int, int> pos = que.front(); que.pop();
        // d_pos := dxyの1つ(pair<int, int>)
        for(auto d_pos: dxy){
            // nx, ny := 次のマス目のx,y座標
            int nx = pos.first + d_pos.first;
            int ny = pos.second + d_pos.second;
            // マス目外ならcontinue
            if(nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
            // 探索済ならcontinue
            if(dist[nx][ny] != INF) continue;
            dist[nx][ny] = dist[pos.first][pos.second] + 1;
            que.push(pair<int, int>(nx, ny));
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dist[i][j] == INF) dist[i][j] = -1;
            if(j == n - 1) cout << dist[i][j] << endl;
            else cout << dist[i][j] << " ";
        }
    }
    return 0;
}