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
    int N, M;
    cin >> N >> M;
    vector<int> X(M);
    for(int i = 0; i < M; i++) cin >> X[i], X[i]--;

    vector<ll> imos(N + 1);
    for(int i = 0; i < M - 1; i++){
        int a = X[i], b = X[i + 1];
        if(a > b) swap(a, b);
        // l: 時計回りの場合, r: 反時計回りの場合
        int l = b - a, r = N - (b - a);
        // [a, b) を閉鎖するとコストが r 増加
        imos[a] += r, imos[b] -= r;
        // [0, a), [b, N) を閉鎖するとコストが l 増加
        imos[b] += l, imos[N] -= l, imos[0] += l, imos[a] -= l;
    }
    for(int i = 0; i < N; i++) imos[i + 1] += imos[i];
    ll ans = *min_element(imos.begin(), imos.end() - 1);
    cout << ans << '\n';
}