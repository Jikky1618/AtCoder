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
    ll L, N1, N2;
    cin >> L >> N1 >> N2;
    vector<pair<ll, ll>> P, Q;
    for(int i = 0; i < N1; i++){
        ll v, l; cin >> v >> l;
        P.push_back({v, l});
    }
    for(int i = 0; i < N2; i++){
        ll v, l; cin >> v >> l;
        Q.push_back({v, l});
    }

    ll ans = 0, i = 0, j = 0, pos1 = 0, pos2 = 0;
    while(1){
        if(i == N1 || j == N2) break;

        auto [v1, l1] = P[i];
        auto [v2, l2] = Q[j];

        if(v1 == v2){
            ans += max(0LL, min(pos1 + l1, pos2 + l2) - max(pos1, pos2));
        }
        if(pos1 + l1 < pos2 + l2){
            pos1 += l1;
            i++;
        }else{
            pos2 += l2;
            j++;
        }
    }

    cout << ans << endl;
}