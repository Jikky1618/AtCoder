#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<ll> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    sort(h.begin(), h.end(), greater<ll>());
    for(int i = 0; i < min(k,n); i++) h[i] = 0;

    ll sum = 0;
    for(int i = 0; i < n; i++){
        sum += h[i];
    }

    cout << sum << endl;

    return 0;
}