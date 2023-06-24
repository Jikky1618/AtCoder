#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<ll> make_is_divisors(ll x){
    vector<ll> divisors;
    for(ll i = 1; i * i <= x; i++){
        if(x % i == 0){
            divisors.emplace_back(i);
            if(x / i != i) divisors.emplace_back(x / i);
        }
    }
    sort(divisors.begin(), divisors.end(), greater<ll>());
    return divisors;
}

// O(N)
ll naive(ll N){
    debug(N);
    ll sum = 0;
    for(int m = 1; m <= N; m++){
        debug(m, N / m, N % m);
        if(N / m == N % m) sum += m;
    }

    return sum;
}

ll solve(ll N){
    auto div = make_is_divisors(N);
    debug(div);

    ll ans = 0;
    // 約数を全列挙
    for(unsigned i = 0; i < div.size(); i++){
        // お気に入りの数を m , そのときの商と余りを r としたとき
        // N = r(m + 1)
        // なので, 約数 - 1 の値が条件を満たすための必要条件
        ll m = div[i] - 1;
        if(m > 0 && N % m == N / m) ans += m;
    }

    return ans;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;
    cout << solve(N) << endl;
}