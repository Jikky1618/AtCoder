#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

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
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].push_back(B);
        G[B].push_back(A);
    }

    vector<int> dist(N, -1), cnt(N);
    queue<int> que;

    dist[0] = 0;
    cnt[0] = 1;
    que.push(0);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(dist[np] != -1){
                if(dist[np] == dist[pos] + 1) cnt[np] += cnt[pos], cnt[np] %= MOD;
                continue;
            }
            dist[np] = dist[pos] + 1;
            cnt[np] = cnt[pos];
            que.push(np);
        }
    }

    cout << cnt[N - 1] << endl;
}