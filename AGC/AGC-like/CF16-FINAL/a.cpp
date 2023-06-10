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
    vector S(H, vector<string>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> S[i][j];
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == "snuke"){
                cout << (char)(j + 'A') << i + 1 << endl;
                return 0;
            }
        }
    }
}