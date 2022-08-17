#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<int> sum(n + 1);
    int ans = 0;
    for(int i = 0; i < n; i++){
        sum[i + 1] += sum[i] + a[i];
        ans += sum[i + 1];
    }
    cout << ans << endl;

    return 0; 
}