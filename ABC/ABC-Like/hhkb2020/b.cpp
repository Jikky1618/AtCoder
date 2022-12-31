#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    int ans = 0;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(i + 1 < H && S[i][j] == '.' && S[i + 1][j] == '.') ans++;
            if(j + 1 < W && S[i][j] == '.' && S[i][j + 1] == '.') ans++;
        }
    }

    cout << ans << endl;
    return 0;
}