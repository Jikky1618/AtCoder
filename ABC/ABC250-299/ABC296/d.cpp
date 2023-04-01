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

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, M;
    cin >> N >> M;

    ll ans = INF;
    // a <= b としても一般性を失わない
    // このとき、a <= ceil(√M) まで全探索すれば十分
    for(ll a = 1; a * a <= ceil(sqrt(M)); a++){
        // このときbはceil(M / a)
        ll b = ceil(M, a);
        if(a <= N && b <= N){
            ans = min(ans, a * b);
        }
    }

    cout << (ans == INF ? -1 : ans) << endl;
}