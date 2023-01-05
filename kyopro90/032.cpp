#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector A(N, vector<int>(N));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) cin >> A[i][j];
    }
    int M;
    cin >> M;
    vector<int> X(M), Y(M);
    for(int i = 0; i < M; i++) cin >> X[i] >> Y[i], X[i]--, Y[i]--;

    // 走ることができない組を配列に入れる
    vector ng(N, vector<int>(N));
    for(int i = 0; i < M; i++){
        ng[X[i]][Y[i]] = 1;
        ng[Y[i]][X[i]] = 1;
    }

    // 順列全探索
    int ans = INF;
    vector<int> P(N);
    iota(P.begin(), P.end(), 0); // 0, 1, ..., N-1
    do{
        int time = 0;
        bool flag = true;
        for(int i = 0; i < N; i++){
            time += A[P[i]][i];
            if(i < N - 1 && ng[P[i]][P[i + 1]] == 1) flag = false;
        }
        if(flag) ans = min(ans, time);
    }while(next_permutation(P.begin(), P.end()));

    cout << (ans == INF ? -1 : ans) << endl;
    return 0;
}