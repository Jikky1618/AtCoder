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

    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) P[i] = {A[i], i};
    sort(P.begin(), P.end());

    int ans = -INF;
    vector<int> seen(N);
    // 金の価格が小さい順から幅優先探索
    for(int i = 0; i < N; i++){
        queue<int> que;
        que.emplace(P[i].second);
        while(!que.empty()){
            int pos = que.front(); que.pop();
            for(auto&& np: G[pos]){
                if(seen[np]) continue;
                seen[np] = true;
                ans = max(ans, A[np] - P[i].first);
                que.emplace(np);
            }
        }
    }

    cout << ans << endl;
}