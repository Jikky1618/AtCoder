#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> v(n), c(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    for(int i = 0; i < n; i++) cin >> c[i];

    int ans = 0;
    for(int i = 0; i < n; i++){
        if(v[i] > c[i]) ans += v[i] - c[i];
    }

    cout << ans << endl;
    return 0;
}