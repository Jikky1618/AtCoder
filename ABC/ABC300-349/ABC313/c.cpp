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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll sum = 0;
    for(int i = 0; i < N; i++) sum += A[i];

    // 操作で総和が変わることはない
    vector<ll> B(N, sum / N);
    // 総和が変わらないので調整
    for(int i = 0; i < sum % N; i++) B[i]++;

    sort(A.begin(), A.end(), greater<ll>());
    ll ans = 0;
    // 値が大きい要素になるだけ, ceil(sum / N) にするコストを割り当てる
    for(int i = 0; i < N; i++) ans += abs(A[i] - B[i]);

    cout << ans / 2 << endl;
}