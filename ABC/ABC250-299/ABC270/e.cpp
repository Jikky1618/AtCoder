#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n,k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    auto check = [&](ll mid){
        ll cnt = 0;
        for(auto &&i: a) cnt += min(mid, i);
        return cnt <= k;
    };

    ll ok = -1, ng = *max_element(a.begin(), a.end()) + 1;
    while(abs(ok - ng) > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    ll cnt = 0;
    for(auto &&i: a){
        cnt += min(i, ok);
        i -= min(i, ok);
    }

    for(auto &&i: a){
        if(cnt == k) break;
        if(i > 0) i--, cnt++;
    }

    for(auto &&i: a) cout << i << " ";
    cout << endl;

    return 0;
}