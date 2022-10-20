#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<vector<int>> x(h + 1,vector<int>(w + 1));
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++) cin >> x[i][j];
    }

    // 二次元累積和
    vector<vector<int>> s(h + 10,vector<int>(w + 10));
    // 横方向に累積
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++) s[i][j] = s[i][j - 1] + x[i][j];
    }
    // 縦方向に累積
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++) s[i][j] = s[i - 1][j]; 
    }

    // クエリ処理
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int ans = s[c][d] - s[a - 1][d] - s[c][b - 1] + s[a - 1][b - 1];
        cout << ans << endl;
    }
    return 0;
}