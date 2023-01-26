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
    vector X(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> X[i][j];
        }
    }
    int Q;
    cin >> Q;

    // 二次元累積和
    vector S(H + 1, vector<int>(W + 1));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            S[i + 1][j + 1] = S[i][j + 1] + S[i + 1][j] - S[i][j] + X[i][j];
        }
    }

    // クエリに答える
    while(Q--){
        int A, B, C, D; cin >> A >> B >> C >> D, A--, B--;
        cout << S[C][D] - S[A][D] - S[C][B] + S[A][B] << '\n';
    }
}