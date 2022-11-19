#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H,W,N,h,w;
    cin >> H >> W >> N >> h >> w;
    vector a(H,vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> a[i][j];
    }

    // sum[n][i][j] := nがi,jにあるなら 1 なければ 0
    vector s(N+2, vector(H+2, vector<int>(W+2)));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            s[a[i][j]][i+1][j+1]++;
        }
    }

    for(int n = 1; n <= N; n++){
        for(int i = 0; i < H+2; i++){
            for(int j = 0; j < W+1; j++) s[n][i][j+1] += s[n][i][j];
        }
    }
    for(int n = 1; n <= N; n++){
        for(int i = 0; i < H+1; i++){
            for(int j = 0; j < W+2; j++) s[n][i+1][j] += s[n][i][j];
        }
    }

    for(int i = 0; i <= H - h; i++){
        for(int j = 0; j <= W - w; j++){
            int ans = 0;
            // s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
            for(int n = 1; n <= N; n++){
                if(s[n][H][W] - (s[n][i+h][j+w] - s[n][i][j+w] - s[n][i+h][j] + s[n][i][j]) > 0) ans++;
            }
            cout << ans << " ";
        }
        cout << endl;
    }

    return 0;
}