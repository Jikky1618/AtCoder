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
    int N, K;
    cin >> N >> K;

    int ans = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            int k = K - i - j;
            if(1 <= k && k <= N) ans++;
        }
    }

    cout << ans << endl;
}