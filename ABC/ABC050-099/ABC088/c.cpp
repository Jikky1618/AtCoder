#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<vector<int>> grid(3,vector<int>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cin >> grid[i][j];
    }

    bool ans = false;
    for(int a1 = 0; a1 <= 100; a1++){
        for(int a2 = 0; a2 <= 100; a2++){
            for(int a3 = 0; a3 <= 100; a3++){
                auto tmp = grid; // ループを回す用
                
                for(int j = 0; j < 3; j++){
                    tmp[0][j] -= a1;
                    tmp[1][j] -= a2;
                    tmp[2][j] -= a3;
                }

                bool flag = true;
                for(int i = 0; i < 3; i++){
                    if(tmp[0][i] != tmp[1][i] || tmp[1][i] != tmp[2][i]){
                        flag = false;
                    }
                }
                if(flag) ans = true;
            }
        }
    }

    if(ans) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}