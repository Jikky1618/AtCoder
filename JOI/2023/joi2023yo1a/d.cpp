#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> a(2 * n - 1);
    for(int i = 0; i < 2 * n - 1; i++) cin >> a[i];

    vector<int> cnt(n+1);
    for(int i = 0; i < 2 * n - 1; i++){
        cnt[a[i]]++;
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        if(cnt[i] == 1) ans = i;
    }

    cout << ans << endl;
    return 0;
}