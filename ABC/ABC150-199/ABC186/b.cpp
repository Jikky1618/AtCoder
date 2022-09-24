#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1<<29;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,w;
    cin >> h >> w;
    vector<vector<int>> a(h,vector<int>(w));
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++) cin >> a[i][j];
    }

    int a_min = INF;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            a_min = min(a_min,a[i][j]);
        }
    }

    int ans = 0;
    for(int i = 0; i < h; i++){
        for(int j = 0; j < w; j++){
            ans += a[i][j] - a_min;
        }
    }

    cout << ans << endl;

    return 0;
}