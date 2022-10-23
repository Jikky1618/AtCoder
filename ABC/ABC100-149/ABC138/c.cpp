#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    sort(v.begin(), v.end());
    double ans = v[0];
    for(int i = 1; i < n; i++){
        ans = (ans + v[i]) / 2;
    }

    cout << ans << endl;
    return 0;
}