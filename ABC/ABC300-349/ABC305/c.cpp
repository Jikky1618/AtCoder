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

    int minH = 1000, minW = 1000, maxH = -1, maxW = -1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.') continue;
            minH = min(minH, i);
            minW = min(minW, j);
            maxH = max(maxH, i);
            maxW = max(maxW, j);
        }
    }

    debug(minH, minW, maxH, maxW);
    for(int i = minH; i <= maxH; i++){
        for(int j = minW; j <= maxW; j++){
            if(S[i][j] == '.'){
                cout << i + 1 << " " << j + 1 << endl;
                return 0;
            }
        }
    }
}