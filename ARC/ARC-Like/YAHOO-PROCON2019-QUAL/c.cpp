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
    ll K, A, B;
    cin >> K >> A >> B;

    ll ans = 0;
    if(2 < B - A){
        K -= (A - 1);
        ans = (K / 2) * (B - A) + K % 2 + A;
    }else{
        ans = 1 + K;
    }

    cout << ans << endl;
}