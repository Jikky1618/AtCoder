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
    double W, H, x, y;
    cin >> W >> H >> x >> y;
    // 分割する面積は半分
    double ans1 = W * H / 2;
    int ans2;
    // 長方形の中心にあれば複数ある
    if(W == 2 * x && H == 2 * y){
        ans2 = 1;
    }else{
        ans2 = 0;
    }

    cout << ans1 << " " << ans2 << endl;
}