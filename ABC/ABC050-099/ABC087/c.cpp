#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<int>> a(2, vector<int>(n));
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j <= i; j++) cnt += a[0][j];
        cnt += a[1][i];
        for(int j = i + 1; j < n; j++) cnt += a[1][j];
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}