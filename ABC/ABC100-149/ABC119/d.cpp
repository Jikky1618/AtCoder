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
    int A, B, Q;
    cin >> A >> B >> Q;
    vector<ll> S(A), T(B);
    for(int i = 0; i < A; i++) cin >> S[i];
    for(int i = 0; i < B; i++) cin >> T[i];
    

    while(Q--){
        ll x; cin >> x;
        // x 地点からすぐ近くのS, Tを格納
        vector<ll> S2, T2;
        auto itr1 = lower_bound(S.begin(), S.end(), x);
        auto itr2 = lower_bound(T.begin(), T.end(), x);
        if(itr1 != S.begin()) S2.emplace_back(*prev(itr1));
        if(itr1 != S.end()) S2.emplace_back(*itr1);
        if(itr2 != T.begin()) T2.emplace_back(*prev(itr2));
        if(itr2 != T.end()) T2.emplace_back(*itr2);
        debug(S2, T2);

        ll ans = INF;
        for(auto s: S2){
            for(auto t: T2){
                ll val = 0;
                // 場合分け
                if((s <= x && x <= t) || (t <= x && x <= s)){
                    val = min(abs(x - s) * 2 + abs(x - t), abs(x - s) + abs(x - t) * 2);
                }else{
                    val = max(abs(x - s), abs(x - t));
                }
                debug(x, S2, T2, val);
                ans = min(ans, val);
            }
        }
        cout << ans << "\n";
    }
}