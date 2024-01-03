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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i] -= i + 1;

    // |A_i - i - b| の総和を最小化
    sort(A.begin(), A.end());

    // 絶対値最小は中央値
    int b = A[N / 2];
    ll ans = 0;
    for(int i = 0; i < N; i++) ans += abs(A[i] - b);

    cout << ans << endl;
}