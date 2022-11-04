#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> b = a;
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(),b.end()),b.end());

    for(int i = 0; i < n; i++){
        a[i] = lower_bound(b.begin(), b.end(),a[i]) - b.begin();
    }

    for(auto &&ans: a) cout << ans << endl;
    return 0;
}