#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<int> c(n);
    for(int i = 0; i < n; i++) cin >> c[i];

    vector<int> d(n);
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            if(i == j) continue;
            if(c[i] % c[j] == 0) cnt++;
        }
        d[i] = cnt;
    }

    double ans = 0.0;
    for(int i = 0; i < n; i++){
        if(d[i] % 2 == 0){
            ans += (double)(d[i] + 2) / (double)(2 * d[i] + 2);
        }else{
            ans += 0.5;
        }
    }

    cout << ans << endl;
    return 0;
}