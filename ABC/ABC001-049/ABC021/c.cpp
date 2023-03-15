#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;
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
    int N, a, b, M;
    cin >> N >> a >> b >> M, a--, b--;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int x, y; cin >> x >> y, x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }

    vector<int> num(N), dist(N, INF);
    queue<int> que;
    num[a] = 1, dist[a] = 0;
    que.push(a);

    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(dist[np] > dist[pos] + 1){
                num[np] = num[pos];
                dist[np] = dist[pos] + 1;
                que.push(np);
            }else if(dist[np] == dist[pos] + 1){
                num[np] += num[pos], num[np] %= MOD;
            }
        }
    }

    debug(num);
    cout << num[b] << endl;
}