#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n),b(n),c(n - 1);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n - 1; i++) cin >> c[i];

    int ans = 0,last = -1;
    for(int i = 0; i < n; i++){
        ans += b[a[i] - 1];
        if(a[i] - 1 == last) ans += c[last - 1];
        last = a[i];
    }

    cout << ans << endl;
    return 0;
}