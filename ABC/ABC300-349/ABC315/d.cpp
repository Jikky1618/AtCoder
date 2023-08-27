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

    int nH = H, nW = W;
    vector<int> fx(H), fy(W);
    for(int _ = 0; _ <= 4000; _++){
        vector<pair<int, char>> dx, dy; // 消す予定の行と列
        // 各行を見る
        for(int i = 0; i < H; i++){
            // i 行目が全て同じかを確認する
            if(fx[i]) continue;
            for(char c = 'a'; c <= 'z'; c++){
                if(X[i][c - 'a'] == nW && nW >= 2){
                    // i 行目に印をつける
                    dx.emplace_back(i, c);
                }
            }
        }
        // 各列を見る
        for(int j = 0; j < W; j++){
            for(char c = 'a'; c <= 'z'; c++){
                // i 列目が全て同じかを確認する
                if(fy[j]) continue;
                if(Y[j][c - 'a'] == nH && nH >= 2){
                    // j 列目に印をつける
                    dy.emplace_back(j, c);
                }
            }
        }
        for(auto [x, c]: dx){
            fx[x] = true;
            for(int y = 0; y < W; y++){
                Y[y][c - 'a']--;
                C[x][y] = '.';
            }
            nH--;
        }
        for(auto [y, c]: dy){
            fy[y] = true;
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

    cout << ans << endl;
}