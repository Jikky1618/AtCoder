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
    vector A(2 * N, vector<ll>(2 * N));
    for(int i = 0; i < 2 * N; i++){
        for(int j = i + 1; j < 2 * N; j++){
            cin >> A[i][j];
        }
    }

    debug(A);
    ll ans = 0;
    auto dfs = [&](auto &&self, int bit, ll val) -> void {
        if(bit == ((1 << (2 * N))) - 1){
            ans = max(ans, val);
            return;
        }

        int p = 0;
        for(int i = 0; i < 2 * N; i++){
            if((bit >> i) & 1) continue;
            p = i;
            break;
        }

        for(int i = p + 1; i < 2 * N; i++){
            if((bit >> i) & 1) continue;
            self(self, bit | (1 << p) | (1 << i), val ^ A[p][i]);
        }
    };

    dfs(dfs, 0, 0);
    cout << ans << endl;
}