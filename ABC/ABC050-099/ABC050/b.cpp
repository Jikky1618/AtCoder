#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> T(N);
    for(int i = 0; i < N; i++) cin >> T[i];
    int M;
    cin >> M;
    vector<int> P(M), X(M);
    for(int i = 0; i < M; i++) cin >> P[i] >> X[i];

    for(int i = 0; i < M; i++){
        int t = 0;
        for(int j = 0; j < N; j++){
            if(j == P[i] - 1) t += X[i];
            else t += T[j];
        }
        cout << t << endl;
    }
    return 0;
}