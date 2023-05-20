#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const vector<int> dx = {0, 1, 1, 1, 0, -1, -1, -1};
const vector<int> dy = {1, 1, 0, -1, -1, -1, 0, 1};

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] != 's') continue;
            for(int k = 0; k < 8; k++){
                bool flag = true;
                for(int l = 0; l < 5; l++){
                    int nx = i + dx[k] * l, ny = j + dy[k] * l;
                    if(nx >= H || nx < 0 || ny >= W || ny < 0){
                        flag = false;
                        break;
                    }
                    if(S[nx][ny] != string("snuke")[l]){
                        flag = false;
                        break;
                    }
                }

                if(flag){
                    for(int l = 0; l < 5; l++){
                        int nx = i + dx[k] * l, ny = j + dy[k] * l;
                        cout << nx + 1 << " " << ny + 1 << endl;
                    }
                }
            }
        }
    }
}