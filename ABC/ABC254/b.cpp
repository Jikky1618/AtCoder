#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<int>> seq(n);
    for(int i = 0; i < n; i++){
        seq[i] = vector<int>(i + 1); // 配列に配列を代入
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            if(j == 0 || j == i) seq[i][j] = 1;
            else seq[i][j] = seq[i-1][j-1] + seq[i-1][j];
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            cout << seq[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}