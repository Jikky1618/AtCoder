#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> X(N), Y(N), P(M), Q(M);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    for(int i = 0; i < M; i++) cin >> P[i] >> Q[i];

    // 訪問する宝箱の集合を固定
    for(int bit = 0; bit < (1 << M); bit++){
        
    }
}