#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,x;
    cin >> n >> x;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int ans = find(p.begin(), p.end(),x) - p.begin() + 1;
    cout << ans << endl;
    return 0;
}