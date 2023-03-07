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
    ll N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    map<int, ll> mp;
    for(int i = 0; i < N; i++) mp[A[i]]++;

    // 余事象を考える
    ll ans = N * (N - 1) / 2;
    for(auto [key, val]: mp){
        ans -= val * (val - 1) / 2;
    }

    cout << ans << endl;
}