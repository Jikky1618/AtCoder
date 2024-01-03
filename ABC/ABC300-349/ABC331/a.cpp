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
    int y, m, M, d, D;
    cin >> M >> D >> y >> m >> d;

    if(m == M && d == D){
        cout << y + 1 << " " << 1 << " " << 1 << '\n';
    }else if(d == D){
        cout << y << " " << m + 1 << " " << 1 << '\n';
    }else{
        cout << y << " " << m << " " << d + 1 << '\n';
    }
}