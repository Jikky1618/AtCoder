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

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W - 1; j++){
            if(S[i][j] == 'T' && S[i][j + 1] == 'T'){
                S[i][j] = 'P', S[i][j + 1] = 'C';
            }
        }
    }

    debug(S);
    for(int i = 0; i < H; i++){
        cout << S[i] << "\n";
    }
}