#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<string> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    bool flag = false;
    for(int i = 0; i < N - M + 1; i++){
        for(int j = 0; j < N - M + 1; j++){
            bool same = true;
            for(int x = 0; x < M; x++){
                for(int y = 0; y < M; y++){
                    if(A[i + x][j + y] != B[x][y]) same = false;
                }
            }
            if(same) flag = true;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
    return 0;
}