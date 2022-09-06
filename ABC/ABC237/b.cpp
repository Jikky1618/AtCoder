#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<int>> A(h,vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            cin >> A[i][j];
        }
    }

    vector<vector<int>> B(w,vector<int>(h));
    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            B[i][j] = A[j][i];
        }
    }

    for(int i = 0; i < w; i++){
        for(int j = 0; j < h; j++){
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}