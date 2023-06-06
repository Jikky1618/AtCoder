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
    int x, y;
    cin >> x >> y;

    int ans = 0;
    // x < y
    if(x < y){
        ans = y - x;
        // x < 0 <= y
        if(x < 0 && 0 <= y){
            ans = min(ans, abs(abs(x) - abs(y)) + 1);
        }
    // y < x
    }else{
        // 0 < y < x
        if(0 < y){
            ans = x - y + 2;
        // 0 <= y < x
        }else if(y == 0){
            ans = x + 1;
        // y < 0 <= x
        }else if(y < 0 && 0 <= x){
            ans = abs(abs(x) - abs(y)) + 1;
        // y < x < 0
        }else{
            ans = abs(y) - abs(x) + 2;
        }
    }

    cout << ans << endl;
}