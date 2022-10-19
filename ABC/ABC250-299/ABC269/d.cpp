#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const vector<int> dx = {-1,-1,0,0,1,1};
const vector<int> dy = {-1,0,-1,1,0,1};

void dfs(int x, int y, vector<vector<int>> &hex){
    hex[x][y] = 0; // 探索済み
    for(int i = 0; i < 6; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx >= 2001 || ny < 0 || ny >= 2001) continue;
        if(hex[nx][ny] == 0) continue;
        dfs(nx, ny, hex); 
    }
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> hex(2010, vector<int>(2010));
    for(int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        hex[x + 1000][y + 1000] = 1; // 黒のマス
    }

    int ans = 0;
    for(int x = 0; x < 2010; x++){
        for(int y = 0; y < 2010; y++){
            // 白のマス or 探索済みならcontinue
            if(hex[x][y] == 0) continue;
            dfs(x, y, hex);
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}