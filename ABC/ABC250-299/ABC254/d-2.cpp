// cf. https://qiita.com/recuraki/items/cbf8587e6930c379d6c4
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// エラトラネスの篩で spf を求める
vector<int> smallest_prime_factor(ll n){
    vector<bool> prime(n + 1, true);
    vector<int> spf(n + 1, -1);
    // 0, 1 は予めふるい落とす
    prime[0] = prime[1] = false;
    spf[1] = 1;

    for(int p = 2; p <= n; p++){
        if(!prime[p]) continue;
        spf[p] = p;
        for(int q = p * 2; q <= n; q += p){
            prime[q] = false;
            // p で割り切れる q の spf を更新
            if(spf[q] == -1) spf[q] = p;
        }
    }
    return spf;
}

vector<pair<int, int>> prime_factorize(ll n, const vector<int>& spf){
    vector<pair<int, int>> factor;
    while(n > 1){
        int p = spf[n];
        int exp = 0;
        while(spf[n] == p){
            n /= p;
            exp++;
        }
        factor.emplace_back(p, exp);
    }
    return factor;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    ll ans = 0;
    // N までの平方数を管理
    vector<ll> sq;
    int val = 1;
    while(val * val <= N) sq.emplace_back(val * val), val++;

    auto spf = smallest_prime_factor(N);
    debug(spf);
    for(int x = 1; x <= N; x++){
        auto pf = prime_factorize(x, spf);
        debug(pf);
        // odd := xの「奇数個ある素因数」の積
        int odd = 1;
        for(auto [p, e]: pf){
            if(e % 2 == 1) odd *= p;
        }
        // 平方数とoddの積が y の条件を満たす
        for(auto s: sq){
            if(s * odd > N) break;
            ans++;
        }
    }

    cout << ans << endl;
}