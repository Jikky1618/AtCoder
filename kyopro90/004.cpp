#include <bits/stdc++.h>
using namespace std;

int main(void){
    int h,w;
    cin >> h >> w;
    // 入力
    vector<vector<int>> grid(h,vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> grid[i][j];
        }
    }
    // 前計算
    vector<int> Row(h);
    vector<int> Column(w);
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            Row[i] += grid[i][j];
            Column[j] += grid[i][j];
        }
    }
    // 答えの計算、出力
    vector<vector<int>> ans(h,vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans[i][j] = Row[i] + Column[j] - grid[i][j];
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}