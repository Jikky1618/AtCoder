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
    vector<int> L(N);
    for(int i = 0; i < N; i++) cin >> L[i];

    sort(L.begin(), L.end());

    ll ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            // L[pos] >= L[i] + L[j]を満たすposを二分探索
            int pos = lower_bound(L.begin(), L.end(), L[i] + L[j]) - L.begin();
            // 満たすkの範囲は[j, pos)
            ans += max(0, pos - 1 - j);
        }
    }

    cout << ans << '\n';
}