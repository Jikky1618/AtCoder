#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    int ans = 0;
    vector V(H, vector<int>(W));
    auto dfs = [&](auto&& self, int a, int b, int x, int y) -> void {
        // 全て探索した場合
        if(x == H && y == 0){
            debug(x, y, a, b);
            if(a == 0 && b == 0) ans++;
            return;
        }

        // 次に探索する場所を決定
        int nx, ny;
        if(y == W - 1){
            nx = x + 1;
            ny = 0;
        }else{
            nx = x;
            ny = y + 1;
        }

        // {x, y} に詰めれない場合
        if(V[x][y] == true){
            // nx, ny に遷移
            self(self, a, b, nx, ny);
            return;
        }

        // 詰めれる場合
        // 1x2 の横を詰める
        if(0 < A && y + 1 < W && V[x][y + 1] == false){
            V[x][y] = V[x][y + 1] = true;
            self(self, a - 1, b, nx, ny);
            V[x][y] = V[x][y + 1] = false;
        }
        // 1x2 の縦を詰める
        if(0 < A && x + 1 < H && V[x + 1][y] == false){
            V[x][y] = V[x + 1][y] = true;
            self(self, a - 1, b, nx, ny);
            V[x][y] = V[x + 1][y] = false;
        }
        // 1x1 を詰める
        if(0 < B){
            V[x][y] = true;
            self(self, a, b - 1, nx, ny);
            V[x][y] = false;
        }
    };

    dfs(dfs, A, B, 0, 0);
    cout << ans << endl;
}