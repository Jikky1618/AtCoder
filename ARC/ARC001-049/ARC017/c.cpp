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
    int N, X;
    cin >> N >> X;
    vector<int> w(N);
    for(int i = 0; i < N; i++) cin >> w[i];

    int x = N / 2, y = N - x;
    vector<ll> w1(1 << x);
    for(int bit = 0; bit < (1 << x); bit++){
        for(int i = 0; i < x; i++){
            if((bit >> i) & 1) w1[bit] += w[i];
        }
    }
    vector<ll> w2(1 << y);
    for(int bit = 0; bit < (1 << y); bit++){
        for(int i = 0; i < y; i++){
            if((bit >> i) & 1) w2[bit] += w[x + i];
        }
    }

    // w2 の個数をmapに
    map<int, int> mp;
    for(int i = 0; i < (1 << y); i++) mp[w2[i]]++;

    ll ans = 0;
    for(int i = 0; i < (1 << x); i++){
        ans += mp[X - w1[i]];
    }

    cout << ans << endl;
}