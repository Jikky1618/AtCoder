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
    int N, K;
    cin >> N >> K;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int ans = 0;
    set<vector<string>> seen; // すでに探索済のマスの盤面
    auto dfs = [&](auto&& self, int k) -> void {
        // 既にこのマス盤面が探索済なら return
        if(seen.count(S)) return;
        // 今のマス盤面を探索済にする
        seen.insert(S);
        // もし k = 0 なら答えを増やす
        if(k == 0){
            debug(S);
            ans++;
            return;
        }

        // マスを全探索して、赤色にできるマスを探す
        vector<pair<int, int>> np;
        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                // S[i][j]が赤色にできる条件はS[i][j]が白かつ、四近傍に赤マスがあること
                if(S[i][j] == '#' || S[i][j] == '@') continue;
                bool red = false;
                for(int d = 0; d < 4; d++){
                    int nx = i + dx[d], ny = j + dy[d];
                    if(nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                    if(S[nx][ny] == '@') red = true;
                }
                if(red == true) np.emplace_back(i, j);
            }
        }

        // 次に赤色にできるマスに遷移
        for(auto [nx, ny]: np){
            S[nx][ny] = '@';
            self(self, k - 1);
            S[nx][ny] = '.';
        }
    };

    // 開始する点を全探索
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            if(S[i][j] == '#') continue;
            S[i][j] = '@'; // 赤色に塗る
            dfs(dfs, K - 1); // あと K - 1 回塗れる
            S[i][j] = '.';
        }
    }

    cout << ans << endl;
}