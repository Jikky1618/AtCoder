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

    set<vector<vector<int>>> st;
    // V[i][j] := (0 := 縦1x2の畳, 1 := 横1x2の畳, -1 := 空きマス)
    vector V(H, vector<int>(W, -1));
    auto dfs = [&](auto&& self, int pos) -> void {
        // 全て埋め終わった場合
        if(pos == A){
            // V の空きマスがちょうど B 個なら敷き詰めれる
            int space = 0;
            for(int i = 0; i < H; i++){
                for(int j = 0; j < W; j++){
                    if(V[i][j] == -1) space++;
                }
            }
            if(space == B){
                st.insert(V);
            }
            return;
        }

        // pos 番目の敷き詰める場所を全探索
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                if(V[i][j] != -1) continue;
                // 横に敷き詰める
                if(j + 1 < W && V[i][j + 1] == -1){
                    V[i][j] = V[i][j + 1] = 0;
                    self(self, pos + 1);
                    V[i][j] = V[i][j + 1] = -1;
                }
                // 縦に敷き詰める
                if(i + 1 < H && V[i + 1][j] == -1){
                    V[i][j] = V[i + 1][j] = 1;
                    self(self, pos + 1);
                    V[i][j] = V[i + 1][j] = -1;
                }
            }
        }
    };

    dfs(dfs, 0);
    debug(st);
    cout << st.size() << endl;
}