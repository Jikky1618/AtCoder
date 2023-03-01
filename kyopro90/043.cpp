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
const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W, rs, cs, rt, ct;
    cin >> H >> W >> rs >> cs >> rt >> ct, rs--, cs--, rt--, ct--;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // 01-BFS
    // dist[x][y][k] := 向きがkのときの(x, y)の最小コスト
    vector dist(H, vector(W, vector<int>(4, INF)));
    deque<tuple<int, int, int>> deq;

    for(int k = 0; k < 4; k++){
        dist[rs][cs][k] = 0;
        deq.push_back({rs, cs, k});
    }

    while(!deq.empty()){
        auto [x, y, dir] = deq.front(); deq.pop_front(); 
        for(int nd = 0; nd < 4; nd++){
            int nx = x + dx[nd], ny = y + dy[nd];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(S[nx][ny] == '#') continue;

            int cost = (dir != nd ? 1 : 0);
            if(dist[nx][ny][nd] > dist[x][y][dir] + cost){
                dist[nx][ny][nd] = dist[x][y][dir] + cost;
                if(cost == 1) deq.push_back({nx, ny, nd});
                else deq.push_front({nx, ny, nd});
            }
        }
    }
    
    cout << *min_element(dist[rt][ct].begin(), dist[rt][ct].end()) << endl;
}