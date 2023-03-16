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
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    ll ans = 0;
    vector seen(H, vector<int>(W));
    queue<tuple<int, int, int>> que;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.') continue;
            // 黒マスからBFS
            seen[i][j] = 1;
            que.push({i, j, 1});
            ll Black = 1, White = 0; // 黒マス、白マスの数
            while(!que.empty()){
                auto [x, y, c] = que.front(); que.pop();
                for(int dir = 0; dir < 4; dir++){
                    int nx = x + dx[dir], ny = y + dy[dir];
                    if(nx >= H || nx < 0 || ny >= W || ny < 0) continue;
                    if(seen[nx][ny] != 0) continue;
                    int nc = (S[nx][ny] == '#');
                    if(nc == c) continue;

                    if(nc == 0) White++;
                    if(nc == 1) Black++;
                    seen[nx][ny] = 1;
                    que.push({nx, ny, nc});
                }
            }
            ans += Black * White;
        }
    }

    cout << ans << endl;
}