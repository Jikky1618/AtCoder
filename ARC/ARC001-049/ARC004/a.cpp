#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<double> x(n), y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    double ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double dist = hypot(x[i] - x[j], y[i] - y[j]);
            ans = max(ans, dist);
        }
    }

    cout << ans << endl;
    return 0;
}