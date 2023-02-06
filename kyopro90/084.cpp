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
    string S;
    cin >> N >> S;

    // o,xの数を累積的に計算
    vector<ll> A(N + 1), B(N + 1);
    for(int i = 0; i < N; i++){
        A[i + 1] = (S[i] == 'o' ? i + 1 : A[i]);
        B[i + 1] = (S[i] == 'x' ? i + 1 : B[i]);
    }

    ll ans = 0;
    for(int i = 0; i <= N; i++){
        ans += min(A[i], B[i]);
    }

    cout << ans << endl;
}