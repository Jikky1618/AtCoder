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
    ll N, K;
    cin >> N >> K;

    // 条件を満たす場合の数
    // 1回 K を出す場合: 6(K - 1)(N - K) 通り
    // 2回 K を出す場合: 3(N - 1) 通り
    // 3回 K を出す場合: 1 通り
    double num = 6 * (K - 1) * (N - K) + 3 * (N - 1) + 1;
    double sum = N * N * N;

    double ans = num / sum;
    cout << ans << endl;
}