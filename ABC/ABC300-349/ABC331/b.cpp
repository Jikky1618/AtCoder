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
    int N, S, M, L;
    cin >> N >> S >> M >> L;
    // S, M, L の個数を全探索
    ll ans = INF;
    for(ll i = 0; i <= N; i++){
        for(ll j = 0; j <= N; j++){
            for(ll k = 0; k <= N; k++){
                ll sum = i * 6 + j * 8 + k * 12;
                if(sum >= N) ans = min(ans, i * S + j * M + k * L);
            }
        }
    }
    cout << ans << endl;

}