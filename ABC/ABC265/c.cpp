#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h,w;
    cin >> h >> w;
    vector<string> grid(h);
    for(int i = 0; i < h; i++) cin >> grid[i];

    vector<vector<bool>> vis(h,vector<bool>(w));
    int i = 0,j = 0;
    while(1){
        if(vis[i][j]){
            cout << -1 << endl;
            return 0;
        }else{
            vis[i][j] = true;
        }
        if(grid[i][j] == 'U'){
            if(i == 0) break;
            else i--;
        }
        else if(grid[i][j] == 'D'){
            if(i == h - 1) break;
            else i++;
        }
        else if(grid[i][j] == 'L'){
            if(j == 0) break;
            else j--;
        }
        else if(grid[i][j] == 'R'){
            if(j == w - 1) break;
            else j++;
        }
    }

    cout << i + 1 << " " << j + 1 << endl;

    return 0;
}
