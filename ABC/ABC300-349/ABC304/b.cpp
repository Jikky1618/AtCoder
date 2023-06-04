#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

ll pow(ll a, ll n){
    ll res = 1;
    while (n > 0){
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
    
    ll A = to_string(N).size();
    if(A <= 3){
        cout << N << endl;
    }else{
        cout << N / pow(10LL, A - 3) * pow(10LL, A - 3) << endl;
    }
}