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

    vector<int> left(n+1), right(n+1);
    for(int i = 0; i < n; i++) left[i + 1] =  gcd(left[i], a[i]);
    for(int i = 0; i < n; i++) right[i + 1] = gcd(right[i], a[n-i-1]);

    int ans = 0;
    for(int i = 0; i < n; i++){
        ans = max(ans, gcd(left[i], right[n-i-1]));
    }
    cout << ans << endl;
    return 0;
}