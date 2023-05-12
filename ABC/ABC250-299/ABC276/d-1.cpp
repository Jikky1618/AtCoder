#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    // 全体のGCDを求める
    int GCD = 0;
    for(int i = 0; i < n; i++) GCD = gcd(GCD, a[i]);
    
    // 全体をGCDで割る
    for(int i = 0; i < n; i++) a[i] /= GCD;

    int ans = 0;
    for(int i = 0; i < n; i++){
        while(a[i] % 2 == 0){
            a[i] /= 2; ans++;
        }
        while(a[i] % 3 == 0){
            a[i] /= 3; ans++;
        }
    }

    bool flag = true;
    for(int i = 0; i < n - 1; i++) if(a[i] != a[i + 1]) flag = false;

    if(flag) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}