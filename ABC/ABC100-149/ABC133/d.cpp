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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // X[0]を求める
    vector<int> X(N);
    for(int i = 0; i < N; i++){
        if(i % 2 == 0) X[0] += A[i];
        else X[0] -= A[i];
    }

    // 他のXを求める
    for(int i = 0; i < N - 1; i++){
        X[i + 1] = 2 * A[i] - X[i];
    }

    for(int i = 0; i < N; i++){
        cout << X[i] << " \n"[i == N - 1];
    }
}