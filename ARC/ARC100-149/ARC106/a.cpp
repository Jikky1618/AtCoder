#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

ll pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res *= a;
        a *= a;
        n >>= 1;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    // A, B を全探索
    // 38 > 18log_3(10) > A
    // 26 > 18log_5(10) > B
    for(ll A = 1; A < 38; A++){
        for(ll B = 1; B < 26; B++){
            ll val = pow(3LL, A) + pow(5LL, B);
            if(val == N){
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;
}