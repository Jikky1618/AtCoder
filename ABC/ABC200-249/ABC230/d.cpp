#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, D;
    cin >> N >> D;
    vector<pair<ll, ll>> P(N);
    for(int i = 0; i < N; i++){
        int L, R; cin >> L >> R;
        P[i].first = L, P[i].second = R;
    }

    sort(P.begin(), P.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });

    ll ans = 0, d = -INF;
    for(int i = 0; i < N; i++){
        if(d + D - 1 < P[i].first){
            ans++;
            d = P[i].second;
        }
    }

    cout << ans << endl;
    return 0;
}