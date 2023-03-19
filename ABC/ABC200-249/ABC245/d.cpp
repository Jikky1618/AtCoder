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
    vector<int> A(N + 1), C(N + M + 1);
    for(int i = 0; i <= N; i++) cin >> A[i];
    for(int i = 0; i <= N + M; i++) cin >> C[i];

    reverse(A.begin(), A.end());
    reverse(C.begin(), C.end());

    vector<int> B(M + 1);
    for(int i = 0; i <= M; i++){
        B[i] = C[i] / A[0];
        for(int j = 1; j <= N; j++){
            C[i + j] -= B[i] * A[j];
        }
    }
    reverse(B.begin(), B.end());
    for(int i = 0; i <= M; i++){
        cout << B[i] << " \n"[i == M];
    }
}