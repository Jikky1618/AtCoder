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

const vector<int> dx = {0, 1, 0, -1};
const vector<int> dy = {1, 0, -1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W, T;
    cin >> H >> W >> T;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int sx, sy, gx, gy;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == 'S') sx = i, sy = j, S[i][j] = '.';
            if(S[i][j] == 'G') gx = i, gy = j, S[i][j] = '.';
        }
    }

    auto check = [&](int mid) -> bool {
        vector dist(H, vector<ll>(W, INF));
        vector done(H, vector<int>(W));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

        dist[sx][sy] = 0;
        pq.push({dist[sx][sy], sx, sy});

        while(!pq.empty()){
            auto [cost, x, y] = pq.top(); pq.pop();
            if(done[x][y]) continue;
            for(int dir = 0; dir < 4; dir++){
                int nx = x + dx[dir], ny = y + dy[dir];
                if(nx >= H || nx < 0 || ny >= W || ny < 0) continue;

                // 白マスの場合
                if(S[nx][ny] == '.' && dist[nx][ny] > dist[x][y] + 1){
                    dist[nx][ny] = dist[x][y] + 1;
                    pq.push({dist[nx][ny], nx, ny});
                }
                // 黒マスの場合
                if(S[nx][ny] == '#' && dist[nx][ny] > dist[x][y] + mid){
                    dist[nx][ny] = dist[x][y] + mid;
                    pq.push({dist[nx][ny], nx, ny});
                }
            }
            done[x][y] = 1;
        }
        return dist[gx][gy] <= T;
    };

    // xを二分探索
    int ok = 0, ng = T + 1;
    while(ng - ok > 1){
        int mid = (ng + ok) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}