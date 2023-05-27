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
    int N, M;
    cin >> N >> M;
    vector A(M, vector<int>(N));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> A[i][j], A[i][j]--;
        }
    }

    vector B(N, vector<int>(N));
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N - 1; j++){
            B[A[i][j]][A[i][j + 1]] = B[A[i][j + 1]][A[i][j]] = true;
        }
    }

    int ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            if(!B[i][j]) ans++;
        }
    }

    cout << ans << endl;
}