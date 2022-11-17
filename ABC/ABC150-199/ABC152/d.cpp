#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;

    vector<vector<int>> cnt(10,vector<int>(10));
    for(int i = 1; i <= n; i++){
        string s = to_string(i);
        cnt[s[0] - '0'][s.back() - '0']++;
    }

    int ans = 0;
    for(int i = 0; i <= 9; i++){
        for(int j = 0; j <= 9; j++){
            ans += cnt[i][j] * cnt[j][i];
        }
    }

    cout << ans << endl;
    return 0;
}