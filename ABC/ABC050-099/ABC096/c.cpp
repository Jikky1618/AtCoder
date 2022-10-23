#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    vector<vector<int>> ans(h,vector<int>(w));
    // 左右２マス
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w - 1; j++){
            if(grid[i][j] == '#' && grid[i][j + 1] == '#'){
                ans[i][j] = 1, ans[i][j + 1] = 1;
            }
        }
    }
    // 上下２マス
    for(int i = 0; i < h - 1; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '#' && grid[i + 1][j] == '#'){
                ans[i][j] = 1, ans[i + 1][j] = 1;
            }
        }
    }

    bool flag = true;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            if(grid[i][j] == '#' && ans[i][j] == 0) flag = false;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}