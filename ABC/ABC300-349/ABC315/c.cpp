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
    vector<int> F(N), S(N);
    for(int i = 0; i < N; i++) cin >> F[i] >> S[i], F[i]--;

    // {味, 美味しさ}
    map<int, vector<ll>> mp;
    for(int i = 0; i < N; i++){
        mp[F[i]].emplace_back(S[i]);
    }

    // すべて異なる味での美味しさの最大値を求める
    vector<ll> M;
    for(auto&& [key, val]: mp){
        sort(val.begin(), val.end(), greater<ll>());
        M.emplace_back(val.front());
    }

    sort(M.begin(), M.end(), greater<ll>());
    ll ans = M[0] + M[1];
    // 同じ味での美味しさの最大を求める
    for(auto&& [key, val]: mp){
        if(val.size() < 2) continue;
        ans = max(ans, (ll)val[0] + (val[1] / 2));
    }

    cout << ans << endl;
}