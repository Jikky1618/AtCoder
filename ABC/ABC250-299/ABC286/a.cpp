#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, P, Q, R, S;
    cin >> N >> P >> Q >> R >> S;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    for(int i = 0; i <= Q - P; i++){
        swap(A[P - 1 + i], A[R - 1 + i]);
    }

    for(int i = 0; i < N; i++) cout << A[i] << " \n"[i == N - 1];
}