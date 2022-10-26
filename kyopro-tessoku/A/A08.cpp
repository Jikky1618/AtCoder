#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<vector<int>> x(h + 1,vector<int>(w + 1));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cin >> x[i][j];
    }

    // 二次元累積和
    vector<vector<int>> s(h + 1,vector<int>(w + 1));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + x[i][j];
    }

    // クエリ処理
    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        int ans = s[c][d] - s[a-1][d] - s[c][b-1] + s[a-1][b-1];
        cout << ans << endl;
    }
    return 0;
}