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
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }

    int ans = 0;
    // bit 全探索

    for(int bit = 0; bit < (1 << (H + W - 2)); bit++){
        if(__builtin_popcount(bit) != H - 1) continue; // 枝刈り
        int x = 0, y = 0;
        set<int> st;
        st.insert(A[x][y]);
        for(int i = 0; i < H + W - 2; i++){
            if((bit >> i) & 1){
                x++;
                if(x >= H) break;
            }else{
                y++;
                if(y >= W) break;
            }
            st.insert(A[x][y]);
        }

        if(int(st.size()) == H + W - 1) ans++;
    }

    cout << ans << endl;
}