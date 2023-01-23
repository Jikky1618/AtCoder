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
    vector<ll> A(2 * N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // 累積和
    vector<ll> S(2 * N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];
    for(int i = 0; i < N; i++) S[N + i + 1] = S[N + i] + A[i];

    for(int l = 0; l < 2 * N; l++){
        while()
    }
}