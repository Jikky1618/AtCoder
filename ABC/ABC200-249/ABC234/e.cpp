#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll X;
    cin >> X;

    // 等差数はそこまで多くないので全探索
    ll ans = INF;
    // 初項を全探索
    for(int first = 1; first <= 9; first++){
        // 公差を全探索
        for(int diff = -9; diff <= 9; diff++){
            string num = "";
            int d = first;
            // 桁数を全探索
            for(int digits = 1; digits <= 18; digits++){
                num += '0' + d;
                if(X <= stoll(num)) ans = min(ans, stoll(num));
                d += diff;
                if(d < 0 || 9 < d) break;
            }
        }
    }

    cout << ans << endl;
}