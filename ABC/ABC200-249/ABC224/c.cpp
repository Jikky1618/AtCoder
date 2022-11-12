#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            for(int k = j + 1; k < n; k++){
                long double a_x = x[j] - x[i];
                long double a_y = y[j] - y[i];
                long double b_x = x[k] - x[i];
                long double b_y = y[k] - y[i];
                long double s = 0.5 * abs(a_x * b_y - a_y * b_x);
                if(s) ans++;
            }
        }
    }

    cout << ans << endl;
    return 0;
}