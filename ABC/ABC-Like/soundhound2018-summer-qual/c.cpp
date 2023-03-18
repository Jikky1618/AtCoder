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
    ll n, m, d;
    cin >> n >> m >> d;

    double p = 0;
    if(d == 0){
        p = (double)1 / n;
    }else{
        p = (double)2 * (n - d) / (n * n);
    }

    double e = p * (m - 1);
    cout << e << endl;
}