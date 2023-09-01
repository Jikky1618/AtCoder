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
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(int i = 0; i < H; i++) cin >> C[i];

    // 行, 列ごとに同じ文字が何枚あるかを記録する
    vector X(H, vector<int>(26)), Y(W, vector<int>(26));
    for(int j = 0; j < W; j++){
        for(int i = 0; i < H; i++){
            X[i][C[i][j] - 'a']++;
            Y[j][C[i][j] - 'a']++;
        }
    }

    // 現在残っている行と列の数
    int nH = H, nW = W;
    // 行と列をすでに消しているかを管理
    vector<int> fx(H), fy(W);
    while(1){
        vector<pair<int, char>> dx, dy; // 印を付ける行と列
        // 各行を見る
        for(int i = 0; i < H; i++){
            // すでに消している行は continue
            if(fx[i]) continue;
            // i 行目が全て同じかを確認する
            for(char c = 'a'; c <= 'z'; c++){
                if(X[i][c - 'a'] == nW && nW >= 2){
                    // i 行目に印をつける
                    dx.emplace_back(i, c);
                }
            }
        }
        // 各列を見る
        for(int j = 0; j < W; j++){
            // すでに消している列は continue
            if(fy[j]) continue;
            for(char c = 'a'; c <= 'z'; c++){
                // i 列目が全て同じかを確認する
                if(Y[j][c - 'a'] == nH && nH >= 2){
                    // j 列目に印をつける
                    dy.emplace_back(j, c);
                }
            }
        }

        // 印を付ける行と列がなければ終了
        if(dx.empty() && dy.empty()) break;

        // 印を付けた行を全て消す
        for(auto [x, c]: dx){
            fx[x] = true;
            // 全ての列の c の個数を 1 減らす
            for(int y = 0; y < W; y++){
                Y[y][c - 'a']--;
                C[x][y] = '.';
            }
            nH--;
        }
        // 印を付けた列を全て消す
        for(auto [y, c]: dy){
            fy[y] = true;
            // 全ての行の c の個数を 1 減らす
            for(int x = 0; x < H; x++){
                X[x][c - 'a']--;
                C[x][y] = '.';
            }
            nW--;
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(C[i][j] != '.') ans++;
        }
    }

    cout << ans << '\n';
}