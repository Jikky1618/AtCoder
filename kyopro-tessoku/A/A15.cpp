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

    vector<int> an = a;
    sort(an.begin(), an.end());
    an.erase(unique(an.begin(),an.end()),an.end());
    for(int i = 0; i < n; i++){
        a[i] = lower_bound(an.begin(), an.end(),a[i]) - an.begin() + 1;
    }

    for(auto &&ans: a) cout << ans << " ";
    cout << endl;
    return 0;
}