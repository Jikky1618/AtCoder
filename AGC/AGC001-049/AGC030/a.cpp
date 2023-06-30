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
    ll A, B, C;
    cin >> A >> B >> C;

    // 交互に食べて, 毒入りクッキーを全て食べれる場合
    if(A + B + 1 >= C){
        cout << B + C << endl;
    // 食べれない場合
    }else{
        cout << B + (A + B + 1) << endl;
    }
}