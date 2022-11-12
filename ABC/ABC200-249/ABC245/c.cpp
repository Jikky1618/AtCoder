#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    //dp1[i] := X[i-1]まで考慮したとき、X[i]をA[i]にしても良いか
    vector<int> dp1(n);
    // dp2[i] := X[i-1]まで考慮したとき、X[i]をB[i]にしても良いか
    vector<int> dp2(n);
    // 初期化
    dp1[0] = dp2[0] = 1;
    for(int i = 0; i < n - 1; i++){
        dp1[i + 1] = (dp1[i] && (abs(a[i] - a[i + 1]) <= k)) || (dp2[i] && (abs(b[i] - a[i + 1]) <= k));
        dp2[i + 1] = (dp1[i] && (abs(a[i] - b[i + 1]) <= k)) || (dp2[i] && (abs(b[i] - b[i + 1]) <= k));
    }

    if(dp1[n - 1] || dp2[n - 1]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}