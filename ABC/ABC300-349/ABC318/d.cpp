#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    vector G(N, vector<ll>(N));
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int D; cin >> D;
            G[i][j] = G[j][i] = D;
        }
    }
    debug(G);

    // bitDP
    // dp[S] := 通った頂点の集合が S であるときの最小コスト
    vector<ll> dp(1 << N);
    for(int bit = 0; bit < (1 << N); bit++){
        // 頂点 nx を全探索
        for(int nx = 0; nx < N; nx++){
            if((bit >> nx) & 1) continue;
            // nx とペアにする頂点 nx2 を全探索
            for(int nx2 = nx + 1; nx2 < N; nx2++){
                if((bit >> nx2) & 1) continue;
                if(nx == nx2) continue;

                // nx と nx2 をペアにする
                int nbit = bit | (1 << nx) | (1 << nx2);
                dp[nbit] = max(dp[nbit], dp[bit] + G[nx][nx2]);
            }
        }
    }
    
    ll ans = *max_element(dp.begin(), dp.end());
    cout << ans << endl;
}