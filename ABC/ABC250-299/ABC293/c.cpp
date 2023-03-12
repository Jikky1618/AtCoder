#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {0, 1};
const vector<int> dy = {1, 0};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }

    int ans = 0;
    set<int> seen;
    auto dfs = [&](auto&& self, pair<int, int> pos) -> void {
        auto [x, y] = pos;
        if(seen.count(A[x][y])) return;
        if(x == H - 1 && y == W - 1){
            ans++;
            return;
        }

        seen.insert(A[x][y]);
        for(int i = 0; i < 2; i++){
            int nx = x + dx[i], ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= H || ny >= W) continue;
            self(self, {nx, ny});
        }
        seen.erase(A[x][y]);
    };

    dfs(dfs, {0, 0});
    cout << ans << endl;
}