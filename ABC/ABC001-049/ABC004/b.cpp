#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<vector<char>> c(4, vector<char>(4));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cin >> c[i][j];
    }

    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            cout << c[3 - i][3 - j] << " ";
        }
        cout << endl;
    }
    return 0;
}