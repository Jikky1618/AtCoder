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
    int K;
    cin >> K;

    int val = 7 % K;
    // 鳩の巣原理より K 回までで十分
    for(int i = 1; i <= K; i++){
        if(val == 0){
            cout << i << endl;
            return 0;
        }
        val = (10 * val + 7) % K;
    }

    cout << -1 << endl;
}