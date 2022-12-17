#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }

    // 前計算
    vector<int> h(H), w(W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) h[i] += A[i][j];
    }
    for(int i = 0; i < W; i++){
        for(int j = 0; j < H; j++) w[i] += A[j][i];
    }

    vector Ans(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            Ans[i][j] = h[i] + w[j] - A[i][j];
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << Ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}