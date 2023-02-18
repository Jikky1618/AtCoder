#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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

    ll Max = 0;
    for(int i = 0; i <= X; i++){
        Max = i * (i + 1) / 2;
        if(Max >= X){
            cout << i << endl;
            return 0;
        }
    }
}