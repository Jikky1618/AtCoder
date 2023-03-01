#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// n進数の文字列xを10進数に変換
ll n_to_dec(string x, ll n){
    assert(2 <= n && n <= 10);
    ll res = 0, base = 1, size = x.size();
    for(int i = size - 1; i >= 0; i--){
        res += 1LL * (x[i] - '0') * base;
        base *= n;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll K;
    string A, B;
    cin >> K >> A >> B;
    
    ll a = n_to_dec(A, K), b = n_to_dec(B, K);

    cout << a * b << endl;
}