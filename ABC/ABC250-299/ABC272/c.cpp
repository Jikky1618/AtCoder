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

    vector<int> odd,even;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 1) odd.push_back(a[i]);
        if(a[i] % 2 == 0) even.push_back(a[i]);
    }

    sort(odd.begin(), odd.end(),greater<int>());
    sort(even.begin(), even.end(),greater<int>());

    int ans = -1;
    if(odd.size() >= 2) ans = max(ans, odd[0] + odd[1]);
    if(even.size() >= 2) ans = max(ans, even[0] + even[1]);

    cout << ans << endl;
    return 0;
}