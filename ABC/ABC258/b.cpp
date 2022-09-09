#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> grid(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            char c;
            cin >> c;
            grid[i][j] = c - '0';
        }
    }

    ll ans = 0;
    // 8近傍用配列
    vector<int> dx = {1,1,1,0,-1,-1,-1,0};
    vector<int> dy = {1,0,-1,-1,-1,0,1,1};
    // A[i][j]は初期位置
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // 8方向
            for(int k = 0; k < 8; k++){
                ll now = 0;
                ll x = i,y = j;
                // n-1回
                for(int l = 0; l < n; l++){
                    now *= 10;
                    now += grid[x][y];
                    x = (x + dx[k] + n) % n;
                    y = (y + dy[k] + n) % n;
                }
                ans = max(ans,now);
            }
        }
    }

    cout << ans << endl;

    return 0;
}