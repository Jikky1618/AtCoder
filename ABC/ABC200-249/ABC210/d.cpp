#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll H, W, C;
    cin >> H >> W >> C;
    vector A(H, vector<ll>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }

    ll ans = INF;
    for(int type = 0; type < 2; type++){
        vector d(H, vector<ll>(W, INF));
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                d[i][j] = A[i][j] - C * (i + j);
            }
        }

        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(0 < i) d[i][j] = min(d[i][j], d[i - 1][j]);
                if(0 < j) d[i][j] = min(d[i][j], d[i][j - 1]);
            }
        }

        debug(d);

        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                ans = min(ans, d[i][j] + A[i][j] + (i + j) * C);
            }
        }
        
        reverse(A.begin(), A.end());
    }

    cout << ans << endl;
}