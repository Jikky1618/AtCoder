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
    int M, D;
    cin >> M >> D;

    int ans = 0;
    for(int m = 1; m <= M; m++){
        for(int d = 1; d <= D; d++){
            int d1 = d % 10, d10 = d / 10;
            if(d1 < 2 || d10 < 2) continue;
            if(d1 * d10 == m) ans++;
        }
    }

    cout << ans << endl;
}