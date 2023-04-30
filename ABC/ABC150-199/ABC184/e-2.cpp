#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    int start = -1, goal = -1;
    vector<vector<pair<int, int>>> G(H * W + 26);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == '#') continue;
            if(A[i][j] == 'S') start = i * W + j;
            if(A[i][j] == 'G') goal = i * W + j;

            // ワープマスなら超頂点と繋ぐ
            if('a' <= A[i][j] && A[i][j] <= 'z'){
                // from: ワープマスの番号
                // to: 超頂点の番号
                int from = i * W + j, to = H * W + (A[i][j] - 'a');
                G[to].emplace_back(from, 1);
                G[from].emplace_back(to, 0);
            }

            // 4近傍を繋ぐ
            for(int k = 0; k < 4; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W || A[nx][ny] == '#') continue;
                G[i * W + j].emplace_back(nx * W + ny, 1);
                G[nx * W + ny].emplace_back(i * W + j, 1);
            }
        }
    }

    // 01-BFS
    deque<int> deq;
    vector<int> dist(H * W + 26, INF);

    deq.emplace_back(start);
    dist[start] = 0;

    while(!deq.empty()){
        int pos = deq.front(); deq.pop_front();
        for(auto [to, cost]: G[pos]){
            if(dist[to] > dist[pos] + cost){
                dist[to] = dist[pos] + cost;
                if(cost == 0) deq.emplace_front(to);
                else deq.emplace_back(to);
            }
        }
    }

    cout << (dist[goal] == INF ? -1 : dist[goal]) << endl;
}