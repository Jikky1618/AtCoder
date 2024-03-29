#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 素因数分解{素数, 次数}の配列を返す
vector<pair<ll, ll>> prime_factorize(ll n){
    vector<pair<ll, ll>> factor;
    for (ll p = 2; p * p <= n; p++){
        if (n % p != 0) continue;
        ll exp = 0;
        while (n % p == 0){
            exp++;
            n /= p;
        }
        factor.push_back({p, exp});
    }
	if (n != 1) factor.push_back({n, 1});
	return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    vector<int> cnt(N + 1);
    for(int i = 1; i <= N; i++){
        auto pf = prime_factorize(i);
        for(auto [p, e]: pf){
            cnt[p] += e;
        }
    }

    int ans = 0;
    // 素因数分解の指数 + 1の積が75になる組合せを全探索
    // (74 + 1)
    for(int i = 2; i <= N; i++){
        if(74 <= cnt[i]) ans++;
    }
    // (4 + 1) * (14 + 1)
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= N; j++){
            if(i != j && 4 <= cnt[i] && 14 <= cnt[j]) ans++;
        }
    }
    // (2 + 1) * (24 + 1)
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= N; j++){
            if(i != j && 2 <= cnt[i] && 24 <= cnt[j]) ans++;
        }
    }
    // (2 + 1) * (4 + 1) * (4 + 1)
    for(int i = 2; i <= N; i++){
        for(int j = 2; j <= N; j++){
            for(int k = j + 1; k <= N; k++){
                if(i != j && j != k && k != i){
                    if(2 <= cnt[i] && 4 <= cnt[j] && 4 <= cnt[k]) ans++;
                }
            }
        }
    }

    cout << ans << endl;
}