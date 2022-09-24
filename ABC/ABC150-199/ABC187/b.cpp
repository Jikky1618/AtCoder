#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<double> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            double slope = (y[j] - y[i]) / (x[j] - x[i]);
            if(-1 <= slope && slope <= 1) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}