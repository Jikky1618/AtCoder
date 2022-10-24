#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> b(n - 1);
    for(int i = 0; i < n - 1; i++) cin >> b[i];

    vector<int> a(n);
    a[0] = b[0];
    a[n - 1] = b[n - 2];
    for(int i = 1; i < n - 1; i++){
        a[i] = min(b[i - 1], b[i]);
    }
    
    int ans = 0;
    for(auto &&i: a) ans += i;

    cout << ans << endl;
    return 0;
}