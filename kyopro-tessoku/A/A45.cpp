#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    char C;
    string A;
    cin >> N >> C >> A;

    string col = "WBR";

    int val = 0; // スコアを計算(不変量)
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++){
            if(A[i] == col[j]) val += j;
        }
    }

    cout << (C == col[val % 3] ? "Yes" : "No") << endl;
}