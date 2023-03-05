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

    vector<int> cnt(N + 1);
    for(int i = 1; i <= N; i++){
        // i * jの値は高々Nまで
        for(int j = 1; i * j <= N; j++){
            cnt[i * j]++;
        }
    }

    ll ans = 0;
    // ABの値を全探索
    for(int A = 1; A <= N; A++){
        // ABの値は高々Nまで
        for(int B = 1; A * B <= N; B++){
            // CD = N - AB
            ans += cnt[N - A * B];
        }
    }

    cout << ans << endl;
}