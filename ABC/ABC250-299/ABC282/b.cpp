#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int Ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            bool flag = true;
            for(int k = 0; k < M; k++){
                if(S[i][k] == 'x' && S[j][k] == 'x') flag = false;
            }
            if(flag) Ans++;
        }
    }

    cout << Ans << endl;
    return 0;
}