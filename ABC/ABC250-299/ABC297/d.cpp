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
    ll A, B;
    cin >> A >> B;

    ll ans = 0;
    while(A != B){
        if(A > B) swap(A, B);
        if(B % A == 0){
            ans += B / A - 1;
            break;
        }
        ans += B / A;
        B %= A;
    }

    cout << ans << endl;
}