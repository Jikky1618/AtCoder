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
    int R, C;
    cin >> R >> C;
    vector<string> B(R);
    for(int i = 0; i < R; i++) cin >> B[i];

    vector<string> ans = B;

    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            if(B[i][j] == '.' || B[i][j] == '#') continue;
            int val = B[i][j] - '0';
            for(int x = 0; x < R; x++){
                for(int y = 0; y < C; y++){
                    if(abs(x - i) + abs(y - j) <= val){
                        ans[x][y] = '.';
                    }
                }
            }
        }
    }

    for(int i = 0; i < R; i++){
        cout << ans[i] << endl;
    }
}