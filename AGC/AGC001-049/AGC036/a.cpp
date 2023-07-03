#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

template<class T, class U>
T floor(T x, U y){
    return (x ? x / y : (x + y - 1) / y);
}

const ll MAX = 1e9;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll S;
    cin >> S;

    // X1, Y1 を原点にする
    ll X1 = 0, Y1 = 0;
    // S = |X2Y3 - X3Y2|
    // Sを1e9以上の桁と, それ未満の桁で分けるために, X2 = 1e9, X3 = 1 とする
    ll X2 = MAX, X3 = 1;
    // Y3が ceil(S / 1e9) のとき
    ll Y3 = ceil(S, MAX);
    // Y2 = Y3 * 1e9 - S となる
    ll Y2 = Y3 * MAX - S;
    
    cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << " " << X3 << " " << Y3 << endl;
}