#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n;i++) cin >> a[i];

    ll same = 0;
    // a[i] == iの個数
    for(int i = 0; i < n; i++){
        if(i == a[i] - 1) same++;
    }
    ll ans = same * (same - 1) / 2;

    // a[a[j]] == j, a[a[i]] == iの個数
    for(int i = 0; i < n; i++){
        int j = a[i] - 1;
        if(i < j && a[j] - 1 == i) ans++;
    }

    cout << ans << endl;

    return 0;
}