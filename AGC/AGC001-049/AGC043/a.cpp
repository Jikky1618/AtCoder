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

const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // 01-BFS
    vector dist(H, vector<int>(W, INF));
    dist[0][0] = (S[0][0] == '#');
    deque<pair<int, int>> deq;
    deq.emplace_back(0, 0);

    while(!deq.empty()){
        auto [x, y] = deq.front(); deq.pop_front();
        for(int k = 0; k < 2; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(S[x][y] == '.' && S[nx][ny] == '#'){
                if(dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    deq.emplace_back(nx, ny);
                }
            }else{
                if(dist[nx][ny] > dist[x][y]){
                    dist[nx][ny] = dist[x][y];
                    deq.emplace_front(nx, ny);
                }
            }
        }
    }

    debug(dist);
    cout << dist[H - 1][W - 1] << endl;
}