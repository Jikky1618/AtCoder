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
    vector c(10, vector<int>(10));
    for(int i = 0; i < 10; i++){
        for(int j = 0; j < 10; j++) cin >> c[i][j];
    }
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }

    // ワーシャルフロイド法
    auto G = c;
    for(int i = 0; i < 10; i++){
        for(int to = 0; to < 10; to++){
            for(int from = 0; from < 10; from++){
                G[from][to] = min(G[from][to], G[from][i] + G[i][to]);
            }
        }
    }

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] == -1 || A[i][j] == 1) continue;
            ans += G[A[i][j]][1];
        }
    }

    cout << ans << endl;
}