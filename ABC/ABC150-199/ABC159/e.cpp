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
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int ans = H * W;
    // 行の切り方 2^(H-1) 通りを bit 全探索
    for(int bit = 0; bit < (1 << (H - 1)); bit++){
        // B[i] := i 行目は何個目のグループか
        vector<int> B(H);
        B[0] = 0;
        for(int i = 0; i < H - 1; i++){
            if((bit >> i) & 1){
                B[i + 1] = B[i] + 1;
            }else{
                B[i + 1] = B[i];
            }
        }
        debug(B);

        int M = B.back() + 1, cnt = B.back();
        // ok := 全て割ったとき, 条件を満たしているか
        bool ok = true;
        vector<int> sum(M);
        for(int j = 0; j < W; j++){
            vector<int> val(M);
            for(int i = 0; i < H; i++){
                if(S[i][j] == '1'){
                    val[B[i]]++;
                }
            }
            // flag := 割る必要があるかどうか
            bool flag = false;
            for(int i = 0; i < M; i++){
                // 縦の一欠片で K を超える場合は条件を満たさない
                if(val[i] > K){
                    ok = false;
                    break;
                }
                // 越えてしまう場合, 区切る
                if(sum[i] + val[i] > K){
                    flag = true;
                    break;
                }
                sum[i] += val[i];
            }

            // debug(sum, val);
            if(!ok) break;
            if(flag) sum = val, cnt++;
        }
        
        debug(ok, cnt);
        if(ok) ans = min(ans, cnt);
    }

    cout << ans << endl;
}