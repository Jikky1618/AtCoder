#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    vector<vector<int>> bingo(3,vector<int>(3));
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++) cin >> bingo[i][j];
    }
    int n;
    cin >> n;
    vector<int> b(n);
    for(int i = 0; i < n; i++) cin >> b[i];

    vector<vector<int>> flag(3,vector<int>(3));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
                if(bingo[j][k] == b[i]) flag[j][k] = 1;
            }
        }
    }

    bool can = false;
    // 横
    for(int i = 0; i < 3; i++){
        if(flag[i][0] & flag[i][1] & flag[i][2]) can = true;
    }
    // 縦
    for(int i = 0; i < 3; i++){
        if(flag[0][i] & flag[1][i] & flag[2][i]) can = true;
    }
    //ななめ
    if(flag[0][0] & flag[1][1] & flag[2][2]) can = true;
    if(flag[2][0] & flag[1][1] & flag[0][2]) can = true;

    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}