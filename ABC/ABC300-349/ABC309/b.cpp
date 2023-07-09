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
    vector<string> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    debug(A);
    vector<string> B(N, string(N, '0'));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(i == 0){
                if(j != 0) B[i][j] = A[i][j - 1];
            }
            if(j == 0){
                if(i != N - 1) B[i][j] = A[i + 1][j];
            }
            if(i == N - 1){
                if(j != N - 1) B[i][j] = A[i][j + 1];
            }
            if(j == N - 1){
                if(i != 0) B[i][j] = A[i - 1][j];
            }
            if(i != 0 && i != N - 1 && j != 0 && j != N - 1){
                B[i][j] = A[i][j];
            }
        }
    }

    for(int i = 0; i < N; i++) cout << B[i] << '\n';
}