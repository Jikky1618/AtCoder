#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<double> x(n);
    for(int i = 0; i < n; i++){
        string u;
        cin >> x[i] >> u;
        if(u == "BTC") x[i] *= 380000;
    }

    double ans = 0;
    for(int i = 0; i < n; i++) ans += x[i];
    cout << fixed << setprecision(10) << ans << endl;
    return 0;
}