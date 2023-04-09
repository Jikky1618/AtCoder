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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> s(H);
    for(int i = 0; i < H; i++) cin >> s[i];

    vector dist(H, vector<int>(W, -1));
    queue<pair<int, int>> que;
    dist[0][0] = 0;
    que.emplace(0, 0);

    while(!que.empty()){
        auto [x, y] = que.front(); que.pop();
        for(int k = 0; k < 4; k++){
            int nx = x + dx[k], ny = y + dy[k];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(s[nx][ny] == '#' || dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            que.emplace(nx, ny);
        }
    }

    // -1を出力する場合
    if(dist[H - 1][W - 1] == -1){
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(s[i][j] == '.') cnt++;
        }
    }
    
    int ans = cnt - dist[H - 1][W - 1] - 1;

    cout << ans << endl;
}