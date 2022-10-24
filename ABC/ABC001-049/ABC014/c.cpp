#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<int> diff(1000005);
    for(int i = 0; i < n; i++){
        diff[a[i]]++;
        diff[b[i] + 1]--;
    }

    vector<int> sum(1000005);
    for(int i = 0; i <= 1000000; i++) sum[i + 1] = sum[i] + diff[i];

    int ans = 0;
    for(int i = 0; i < 1000005; i++){
        ans = max(ans, sum[i]);
    }

    cout << ans << endl;
    return 0;
}