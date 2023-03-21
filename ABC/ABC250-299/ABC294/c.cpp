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
    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];

    vector<int> C(N + M);
    for(int i = 0; i < N; i++) C[i] = A[i];
    for(int i = 0; i < M; i++) C[i + N] = B[i];

    sort(C.begin(), C.end());
    debug(C);

    vector<int> ansA(N), ansB(M);
    int posA = 0, posB = 0;
    for(int i = 0; i < N + M; i++){
        if(posA < N && C[i] == A[posA]){
            ansA[posA] = i + 1;
            posA++;
        }
        if(posB < M && C[i] == B[posB]){
            ansB[posB] = i + 1;
            posB++;
        }
    }

    for(int i = 0; i < N; i++){
        cout << ansA[i] << " \n"[i == N - 1];
    }
    for(int i = 0; i < M; i++){
        cout << ansB[i] << " \n"[i == M - 1];
    }
}