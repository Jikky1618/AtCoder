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
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    // cnt[i][j] := 横方向で光るマス数
    // cnt2[i][j] := 縦方向で光るマス数
    vector cnt(H, vector<int>(W)), cnt2(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '#') continue;
            // 横方向を調べる
            if(cnt[i][j] == 0){
                int val = 0;
                for(int nx = i; nx < H; nx++){
                    if(S[nx][j] == '#') break;
                    val++;
                }
                // cntを更新
                for(int nx = i; nx < H; nx++){
                    if(S[nx][j] == '#') break;
                    cnt[nx][j] = val;
                }
            }
            // 縦方向を調べる
            if(cnt2[i][j] == 0){
                int val = 0;
                for(int ny = j; ny < W; ny++){
                    if(S[i][ny] == '#') break;
                    val++;
                }
                // cnt2を更新
                for(int ny = j; ny < W; ny++){
                    if(S[i][ny] == '#') break;
                    cnt2[i][ny] = val;
                }
            }
        }
    }
    debug(cnt, cnt2);

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            ans = max(ans, cnt[i][j] + cnt2[i][j] - 1);
        }
    }

    cout << ans << endl;
}