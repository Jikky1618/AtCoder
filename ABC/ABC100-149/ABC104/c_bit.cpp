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
    ll D, G;
    cin >> D >> G;
    vector<ll> p(D), c(D);
    for(int i = 0; i < D; i++) cin >> p[i] >> c[i];

    ll ans = INF;
    // どの問題でコンプリートボーナスを得るかをbit全探索
    for(int bit = 0; bit < (1 << D); bit++){
        // Max: コンプリートしない中での最大得点の問題
        ll point = 0, cnt = 0, Max = -1;
        // コンプリートボーナス分
        for(int i = 0; i < D; i++){
            if((bit >> i) & 1){
                point += (i + 1) * p[i] * 100 + c[i];
                cnt += p[i];
            }else{
                Max = i;
            }
        }
        if(point < G){
            // コンプリートボーナスしない
            ll need = ((G - point) + (Max + 1) * 100 - 1)  / ((Max + 1) * 100);
            if(p[Max] <= need) continue; // コンプリートしないに矛盾
            cnt += need;
            point += need * (Max + 1) * 100;
        }
        if(G <= point) ans = min(ans, cnt);
    }

    cout << ans << endl;
}