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
    int N, C;
    cin >> N >> C;
    vector<int> T(N), A(N);
    for(int i = 0; i < N; i++) cin >> T[i] >> A[i];

    const int MAX = (1 << 30) - 1;
    int s0 = 0, s1 = MAX;
    int X = C;
    for(int i = 0; i < N; i++){
        // s0, s1 に type T[i] の演算を施す
        if(T[i] == 1) s0 &= A[i], s1 &= A[i];
        if(T[i] == 2) s0 |= A[i], s1 |= A[i];
        if(T[i] == 3) s0 ^= A[i], s1 ^= A[i];
        // X の 0 は s0 に 1 は s1 に対応する
        X = (X & s1) | ((X ^ MAX) & s0);
        cout << X << '\n';
    }
}