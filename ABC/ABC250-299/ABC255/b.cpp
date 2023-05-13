#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    int N, K;
    cin >> N >> K;
    vector<int> A(K);
    for(int i = 0; i < K; i++) cin >> A[i], A[i]--;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ll val = INF;
        for(int j = 0; j < K; j++){
            ll x = X[i] - X[A[j]], y = Y[i] - Y[A[j]];
            ll dist = x * x + y * y;
            val = min(val, dist);
        }
        ans = max(ans, val);
    }

    cout << sqrt(ans) << endl;
}