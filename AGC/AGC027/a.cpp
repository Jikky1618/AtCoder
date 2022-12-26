#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N, x;
    cin >> N >> x;
    vector<int> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];

    sort(a.begin(), a.end());
    int ans = 0;
    for(int i = 0; i < N; i++){
        if(a[i] <= x) ans++, x -= a[i];
    }
    if(x > 0 && N == ans) ans--;

    cout << ans << endl;
    return 0;
}