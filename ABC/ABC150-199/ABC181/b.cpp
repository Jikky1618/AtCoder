#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<ll> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += (b[i] - a[i] + 1) * (a[i] + b[i]) / 2;
    }

    cout << sum << endl;

    return 0;
}