#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<vector<int>> d(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> d[i][j];
    }

    // 2次元累積和
    vector<vector<int>> s(n+1,vector<int>(n+1));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) s[i+1][j+1] = s[i+1][j] + s[i][j+1] - s[i][j] + d[i][j];
    }

    // 全ての長方形区間の面積を全探索
    // val[i] := 面積がiのときの美味しさの合計の最大値
    vector<ll> val(n*n+1);
    for(int x1 = 0; x1 < n; x1++){
        for(int x2 = x1 + 1; x2 <= n; x2++){
            for(int y1 = 0; y1 < n; y1++){
                for(int y2 = y1 + 1; y2 <= n; y2++){
                    ll area = (x2 - x1) * (y2 - y1);
                    ll sum = s[x2][y2] - s[x1][y2] - s[x2][y1] + s[x1][y1];
                    val[area] = max(val[area], sum);
                }
            }
        }
    }

    // val[i] := 面積がi「以下」の長方形領域の総和の最大値
    for(int i = 0; i < n*n; i++) val[i+1] = max(val[i+1], val[i]);

    // クエリ処理
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        ll p; cin >> p;
        cout << val[p] << endl;
    }
    return 0;
}