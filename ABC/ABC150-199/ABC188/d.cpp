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
    int N, C;
    cin >> N >> C;
    vector<int> a(N), b(N), c(N);
    for(int i = 0; i < N; i++) cin >> a[i] >> b[i] >> c[i];

    // イベントソート
    vector<pair<int, ll>> event;
    for(int i = 0; i < N; i++){
        event.emplace_back(a[i], c[i]);
        event.emplace_back(b[i] + 1, -c[i]);
    }

    sort(event.begin(), event.end());

    ll ans = 0, val = 0, day = 0;
    for(auto [t, d]: event){
        // 日が進むなら(C, val)の最小値を加算する
        if(day < t){
            ans += min((ll)C, val) * (t - day);
            day = t;
        }
        val += d;
    }

    cout << ans << endl;
}