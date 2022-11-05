#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const vector<int> dx = {0,1,0,-1};
const vector<int> dy = {1,0,-1,0};
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int h,w;
    cin >> h >> w;
    vector<string> c(h);
    for(int i = 0; i < h; i++) cin >> c[i];

    // スタート位置
    int sx = 0, sy = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(c[i][j] == 'S') sx = i, sy = j;
        }
    }

    // グループ分け用グリッド
    vector<vector<int>> grid(h,vector<int>(w, INF));
    queue<pair<int, int>> que;

    for(int i = 0; i < 4; i++){
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
        if(c[nx][ny] == '#') continue;
        grid[nx][ny] = i;
        que.push(pair<int, int>(nx, ny));

        while(!que.empty()){
            pair<int, int> pos = que.front(); que.pop();
            for(int j = 0; j < 4; j++){
                nx = pos.first + dx[j];
                ny = pos.second + dy[j];
                // 場外ならcontinue
                if(nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
                // S or #ならcontinue
                if(c[nx][ny] == 'S' || c[nx][ny] == '#') continue;
                // もし、INF以外 and iではないならYes
                if(grid[nx][ny] != INF && grid[nx][ny] != i){
                    cout << "Yes" << endl;
                    return 0;
                }
                // INF以外ならcontinue
                if(grid[nx][ny] != INF) continue;

                grid[nx][ny] = i;
                que.push(pair<int,int>(nx,ny));
            }
        }
    }
    cout << "No" << endl;

    return 0;
}