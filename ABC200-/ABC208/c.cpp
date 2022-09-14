#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<pair<int,int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }

    sort(a.begin(), a.end());
    vector<ll> ans(n,k / n);
    for(int i = 0; i < k % n; i++){
        ans[a[i].second]++;
    }

    for(int i = 0; i < n; i++) cout << ans[i] << endl;

    return 0;
}