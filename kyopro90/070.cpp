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
    int N;
    cin >> N;
    vector<ll> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    // x, yそれぞれの中央値を求めるためにソート(x, yはそれぞれ独立)
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll ans = 0;
    for(int i = 0; i < N; i++) ans += abs(X[i] - X[N / 2]) + abs(Y[i] - Y[N / 2]);

    cout << ans << endl;
}