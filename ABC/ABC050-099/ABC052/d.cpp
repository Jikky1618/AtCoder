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
    ll N, A, B;
    cin >> N >> A >> B;
    vector<int> X(N);
    for(int i = 0; i < N; i++) cin >> X[i];

    ll ans = 0;
    for(int i = 0; i < N - 1; i++){
        ans += min(B, A * (X[i + 1] - X[i]));
    }

    cout << ans << endl;
}