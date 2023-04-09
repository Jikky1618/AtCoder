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
    int N, M;
    cin >> N >> M;

    vector<vector<pair<int, int>>> G(N);
    for(int i = 0; i < M; i++){
        int L, R, D; cin >> L >> R >> D, L--, R--;
        G[L].emplace_back(R, D);
        G[R].emplace_back(L, -D);
    }

    bool flag = true;
    vector<int> seen(N), dist(N);
    for(int i = 0; i < N; i++){
        if(seen[i]) continue;

        seen[i] = 1, dist[i] = 0;
        queue<int> que;
        que.emplace(i);

        while(!que.empty()){
            int pos = que.front(); que.pop();

            for(auto [np, cost]: G[pos]){
                // 探索済みの場合整合性を確認
                if(seen[np]){
                    if(dist[np] != dist[pos] + cost){
                        flag = false;
                    }
                // 未探索の場合はdist[np]の値を決定
                }else{
                    seen[np] = 1;
                    dist[np] = dist[pos] + cost;
                    que.emplace(np);
                }
            }
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
}