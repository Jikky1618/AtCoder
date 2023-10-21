#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
const vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int ans = 0;
    vector seen(H, vector<bool>(W, false));
    queue<pair<int, int>> que;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(seen[i][j]|| S[i][j] == '.') continue;
            seen[i][j] = true;
            que.emplace(i, j);
            ans++;
            while(!que.empty()){
                auto [x, y] = que.front();
                que.pop();
                for(int k = 0; k < 8; k++){
                    int nx = x + dx[k], ny = y + dy[k];
                    if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                    if(seen[nx][ny] || S[nx][ny] == '.') continue;
                    seen[nx][ny] = true;
                    que.emplace(nx, ny);
                }
            }
        }
    }

    cout << ans << endl;
}