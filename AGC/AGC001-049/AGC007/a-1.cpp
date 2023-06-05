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
    vector<string> A(H);
    for(int i = 0; i < H; i++) cin >> A[i];

    bool flag = false;
    // 右: 0, 下: 1としてbit全探索
    for(int bit = 0; bit < (1 << (H + W - 2)); bit++){
        // H - 1 回下に動いていない場合continue
        if(__builtin_popcount(bit) != H - 1) continue;
        vector<string> S(H, string(W, '.'));
        int x = 0, y = 0;
        S[x][y] = '#';
        for(int i = 0; i < (H + W - 2); i++){
            if((bit >> i) & 1){
                x++;
            }else{
                y++;
            }
            S[x][y] = '#';
        }
        if(A == S) flag = true;
    }

    cout << (flag ? "Possible" : "Impossible") << endl;
}