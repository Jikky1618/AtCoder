#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9 + 7;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 累積和
    vector<int> s(n+1);
    for(int i = 0; i < n; i++) s[i+1] = s[i] + a[i];

    for(auto &&i: s) cout << i << endl;

    return 0;
}