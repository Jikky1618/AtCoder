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
    vector<string> A(H), B(H);
    for(int i = 0; i < H; i++) cin >> A[i];
    for(int i = 0; i < H; i++) cin >> B[i];

    auto rotate = [&](int s, int t) -> vector<string> {
        vector<string> res = A;
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                res[(i - s + H) % H][(j - t + W) % W] = A[i][j];
            }
        }
        return res;
    };

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            vector<string> new_A = A;
            new_A = rotate(i, j);
            if(new_A == B){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
}