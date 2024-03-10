#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    int M = 0;
    while((1 << M) < N) M++;

    // i が飲むワイン
    vector<vector<int>> A(M);
    for(int i = 1; i <= N; i++){
        for(int j = 0; j < M; j++){
            if(i & (1 << j)) A[j].emplace_back(i);
        }
    }

    cout << M << endl;
    for(int i = 0; i < M; i++){
        int K = A[i].size();
        cout << K << " ";
        for(int j = 0; j < K; j++){
            cout << A[i][j] << " \n"[j == K - 1];
        }
        cout << flush;
    }

    string S;
    cin >> S;

    int ans = 0;
    for(int i = 0; i < M; i++){
        if(S[i] == '1') ans |= (1 << i);
    }

    // ans = 0 のときが corner case
    cout << (ans == 0 ? N : ans) << endl;
}