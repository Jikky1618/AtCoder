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
    int N;
    cin >> N;

    // 区間スケジューリング問題に帰着
    vector<pair<ll, ll>> P(N);
    for(int i = 0; i < N; i++){
        ll X, L; cin >> X >> L;
        P[i] = {X - L, X + L};
    }

    sort(P.begin(), P.end(), [&](auto& l, auto& r){
        return l.second < r.second;
    });

    debug(P);
    ll ans = 0, d = -INF;
    for(int i = 0; i < N; i++){
        if(d <= P[i].first){
            ans++;
            d = P[i].second;
        }
    }

    cout << ans << endl;
}