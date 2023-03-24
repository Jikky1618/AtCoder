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
    vector P(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> P[i][j];
    }

    // 行をbit全探索
    int ans = 0;
    for(int bit = 0; bit < (1 << H); bit++){
        map<int, int> same; // 選んだ行の同じ列で同じだった数字
        // 列を全探索
        for(int i = 0; i < W; i++){
            set<int> st; // 列の数字の種類
            for(int j = 0; j < H; j++){
                if(!((bit >> j) & 1)) continue;
                st.insert(P[j][i]);
            }
            if(st.size() == 1) same[*st.begin()]++;
        }
        
        int cnt = 0;
        for(auto [key, val]: same){
            cnt = max(cnt, val);
        }

        ans = max(ans, cnt * __builtin_popcount(bit));
    }

    cout << ans << endl;
}