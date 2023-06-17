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
    int N;
    cin >> N;

    // 1.
    int M = 2 * N;
    cout << M << endl;

    // 2.
    string ans = string(N / 4, '4');
    if(N % 4 != 0){
        ans = (char)(N % 4 + '0') + ans;
    }

    cout << ans << endl;
}