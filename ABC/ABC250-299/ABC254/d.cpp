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

    ll ans = 0;
    for(ll i = 1; i <= N; i++){
        ll k = i;
        // k を p ^ 2 でできるだけ割る
        for(ll p = 2; p * p <= k; p++){
            while(k % (p * p) == 0){
                k /= (p * p);
            }
        }
        // k に平方数をだんだん掛けてN以下になるまで平方数を掛けていく
        for(ll p = 1; k * p * p <= N; p++){
            ans++;
        }
    }

    cout << ans << endl;
}