#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int N,M,C;
    cin >> N >> M >> C;
    vector<int> B(M);
    for(int i = 0; i < M; i++) cin >> B[i];
    vector<vector<int>> A(N,vector<int>(M));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++) cin >> A[i][j];
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        int sum = 0;
        for(int j = 0; j < M; j++){
            sum += A[i][j] * B[j];
        }
        if(sum + C > 0) ans++;
    }

    cout << ans << endl;
    return 0;
}