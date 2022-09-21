#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<vector<char>> a(n,vector<char>(n));

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    bool correct = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            else if(a[i][j] == 'W'){
                if(a[j][i] != 'L') correct = false;
            }
            else if(a[j][i] == 'L'){
                if(a[j][i] != 'W') correct = false;
            }
            else if(a[i][j] == 'D'){
                if(a[j][i] != 'D') correct = false;
            }
        }
    }
    if(correct) cout << "correct" << endl;
    else cout << "incorrect" << endl;

    return 0;
}