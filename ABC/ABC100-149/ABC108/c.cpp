#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef LOCAL
#include <debug.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, K;
    cin >> N >> K;

    if(K % 2 == 0){
        ll a = N / K; // Nまでの数でKで割り切れるもの
        ll b = (N + (K / 2)) / K; // Nまでの数でKで割るとK/2余るもの
        cout << a*a*a + b*b*b << endl;
    }else{
        ll a = N / K; // Nまでの数でKで割り切れるもの
        cout << a*a*a << endl;
    }
}