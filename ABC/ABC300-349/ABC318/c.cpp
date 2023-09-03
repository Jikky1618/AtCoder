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

template<class T, class U>
T ceil(T x, U y){
    return (x > 0 ? (x + y - 1) / y : x / y);
}

template<class T, class U>
T floor(T x, U y){
    return (x > 0 ? x / y : (x + y - 1) / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, D, P;
    cin >> N >> D >> P;
    vector<int> F(N);
    for(int i = 0;i < N; i++) cin >> F[i];

    sort(F.begin(), F.end(), greater<int>());
    // 累積和
    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + F[i];

    ll ans = INF;
    // [0, i) まで無料
    for(int i = 0; i <= N; i++){
        // [0, i) まで無料にするために必要なセット * P 円
        ll cost = ceil(i, D) * P;
        // [i, N) までの料金
        cost += S[N] - S[i];
        ans = min(ans, cost);
    }

    cout << ans << endl;
}