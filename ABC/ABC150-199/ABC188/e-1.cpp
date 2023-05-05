#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int X, Y; cin >> X >> Y, X--, Y--;
        G[X].emplace_back(Y);
    }

    // val[i] := 頂点iから到達できる頂点での最大値
    vector<int> val(N, -INF);
    // 大きい方から見る！
    for(int i = N - 1; i >= 0; i--){
        for(auto&& j: G[i]){
            val[i] = max({val[i], val[j], A[j]});
        }
    }

    int ans = -INF;
    for(int i = 0; i < N; i++) ans = max(ans, val[i] - A[i]);

    cout << ans << endl;
}