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

    vector<string> S2(H, string(W, '.'));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S[i][j] == '.') continue; // #以外なら無視
            bool flag = true;
            for(int k = 0; k < 8; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(S[nx][ny] == '.') flag = false;
            }
            if(flag) S2[i][j] = '#';
        }
    }

    vector<string> S3 = S2;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(S2[i][j] == '#') continue;
            bool flag = false;
            for(int k = 0; k < 8; k++){
                int nx = i + dx[k], ny = j + dy[k];
                if(nx < 0 || nx >= H || ny < 0 || ny >= W) continue;
                if(S2[nx][ny] == '#') flag = true;
            }
            if(flag) S3[i][j] = '#';
        }
    }

    if(S == S3){
        cout << "possible" << endl;
        for(int i = 0; i < H; i++){
            cout << S2[i] << '\n';
        }
    }else{
        cout << "impossible" << endl;
    }
}