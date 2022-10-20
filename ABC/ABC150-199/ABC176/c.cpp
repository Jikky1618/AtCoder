#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for(int i = 1; i < n; i++){
        if(a[i - 1] > a[i]){
            ans += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }

    cout << ans << endl;
    return 0;
}