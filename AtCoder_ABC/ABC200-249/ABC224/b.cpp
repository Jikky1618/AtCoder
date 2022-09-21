#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> grid(h,vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cin >> grid[i][j];
    }

    for(int i_1 = 0; i_1 < h - 1; i_1++){
        for(int i_2 = i_1 + 1; i_2 < h; i_2++){
            for(int j_1 = 0; j_1 < w - 1; j_1++){
                for(int j_2 = j_1 + 1; j_2 < w; j_2++){
                    if(grid[i_1][j_1] + grid[i_2][j_2] > grid[i_2][j_1] + grid[i_1][j_2]){
                        cout << "No" << endl;
                        return 0;
                    }
                }
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}