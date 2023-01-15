#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    deque<pair<ll, ll>> deq;
    while(Q--){
        int q; cin >> q;
        if(q == 1){
            ll x, c; cin >> x >> c;
            deq.push_back({x, c});
        }
        if(q == 2){
            ll c; cin >> c;
            ll ans = 0;
            while(c > 0){
                ll cnt = min(c, deq.front().second);
                ans += deq.front().first * cnt;
                deq.front().second -= cnt, c -= cnt;
                
                if(deq.front().second == 0) deq.pop_front();
            }
            
            cout << ans << "\n";
        }
    }
}