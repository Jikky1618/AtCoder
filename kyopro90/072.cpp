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
    vector<string> C(H);
    for(int i = 0; i < H; i++) cin >> C[i];

    int ans = -1;
    vector seen(H, vector<int>(W));
    auto dfs = [&](auto &&self, pair<int, int> pos, pair<int, int> start, int k) -> void {
        if(k != 0 && pos == start){
            if(k < 3) return;
            ans = max(ans, k);
        }

        for(int i = 0; i < 4; i++){
            auto nx = pos.first + dx[i], ny = pos.second + dy[i];
            if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
            if(C[nx][ny] == '#' || seen[nx][ny]) continue;
            seen[nx][ny] = true;
            self(self, {nx, ny}, start, k + 1);
            seen[nx][ny] = false;
        }
    };
    
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(C[i][j] == '#') continue;
            dfs(dfs, {i, j}, {i, j}, 0);
        }
    }

    cout << ans << endl;
}