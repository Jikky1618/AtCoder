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
    int N, x;
    cin >> N >> x;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> B = A;
    for(int i = 0; i < N - 1; i++){
        if(B[i] > x) B[i] = x;
        if(B[i] + B[i + 1] > x) B[i + 1] = x - B[i];
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += A[i] - B[i];
    }

    cout << ans << endl;
}