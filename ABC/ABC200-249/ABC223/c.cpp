#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<double> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    // 2 つの火がぶつかる時間
    double t = 0;
    for(int i = 0; i < n; i++) t += a[i] / b[i];
    t /= 2;

    double ans = 0;
    for(int i = 0; i < n; i++){
        // min(a[i]全て, 1秒に燃える長さ * t)
        ans += min(a[i], b[i] * t);
        t -= min(a[i] / b[i], t);
    }

    cout << ans << endl;
    return 0;
}