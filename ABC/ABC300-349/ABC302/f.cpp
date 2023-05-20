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
    vector<int> A(N);
    vector<set<int>> S(N);
    for(int i = 0; i < N; i++){
        cin >> A[i];
        for(int j = 0; j < A[i]; j++){
            int s; cin >> s, s--;
            S[i].insert(s);
        }
    }

    // 超頂点を用いる
    vector<vector<int>> G(M + N);
    for(int i = 0; i < N; i++){
        for(auto s: S[i]){
            G[s].emplace_back(M + i);
            G[M + i].emplace_back(s);
        }
    }

    vector<int> dist(M + N, -1);
    queue<int> que;
    for(auto s: G[0]){
        dist[s] = 0;
        que.emplace(s);
    }

    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto np: G[pos]){
            if(dist[np] != -1) continue;
            dist[np] = dist[pos] + 1;
            que.emplace(np);
        }
    }

    int ans = INF;
    for(auto g: G[M - 1]){
        if(dist[g] == -1) continue; // 未到達ならcontinue
        int val = dist[g] / 2; // 2で割る
        ans = min(ans, val);
    }

    cout << (ans == INF ? -1 : ans) << endl;
}