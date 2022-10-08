#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> d(n);
    for(int i  = 0; i < n; i++) cin >> d[i];

    sort(d.begin(), d.end());
    int ans = (d[n / 2] - d[n / 2 - 1]);
    
    cout << ans << endl;
    return 0;
}