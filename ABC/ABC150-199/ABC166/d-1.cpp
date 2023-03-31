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
    ll X;
    cin >> X;

    // 全探索を範囲は-200 ~ 200で十分
    for(ll A = -200; A <= 200; A++){
        for(ll B = -200; B <= 200; B++){
            ll A5 = A * A * A * A * A;
            ll B5 = B * B * B * B * B;
            if(A5 - B5 == X){
                cout << A << " " << B << endl;
                return 0;
            }
        }
    }
}