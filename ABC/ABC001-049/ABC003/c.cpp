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
    int N, K;
    cin >> N >> K;
    vector<double> R(N);
    for(int i = 0; i < N; i++) cin >> R[i];

    sort(R.begin(), R.end(), greater<double>());

    vector<double> V(K);
    for(int i = 0; i < K; i++) V[i] = R[i];

    sort(V.begin(), V.end());

    double ans = 0;
    for(int i = 0; i < K; i++){
        ans = (ans + V[i]) / 2;
    }

    cout << ans << endl;
}