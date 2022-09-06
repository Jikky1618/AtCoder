#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,k;
    cin >> n >> k;
    vector<pair<ll,ll>> ab(n);
    for(int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;
    sort(ab.begin(), ab.end());

    for(int i = 0; i < n; i++){
        if(ab[i].first <= k) k += ab[i].second;
        else break;
    }

    cout << k << endl;

    return 0;
}