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

    int cnt = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) if(A[i][j] == '#') cnt++;
    }

    // # の個数と最短経路の長さが同じならPossible
    cout << (cnt == H + W - 1 ? "Possible" : "Impossible") << endl;
}