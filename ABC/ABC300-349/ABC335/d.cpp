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
    vector A(N, vector<int>(N));
    
    int cnt = 1;
    for(int d = 0; d < N / 2; d++){
        // 上側
        for(int j = d; j < N - 1 - d; j++) A[d][j] = cnt++;
        // 右側
        for(int i = d; i < N - 1 - d; i++) A[i][N - d - 1] = cnt++;
        // 下側
        for(int j = N - 1 - d; j > d; j--) A[N - d - 1][j] = cnt++;
        // 左側
        for(int i = N - 1 - d; i > d; i--) A[i][d] = cnt++;
    }
    debug(A);

    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(A[i][j] == 0){
                cout << 'T' << ' ';
            }else{
                cout << A[i][j] << " \n"[j == N - 1];
            }
        }
    }
}