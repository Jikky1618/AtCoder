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
    int d;
    cin >> d;

    // 累積max
    vector<int> p(n+1),q(n+1);
    for(int i = 0; i < n; i++) p[i+1] = max(p[i], a[i]);
    for(int i = 0; i < n; i++) q[i+1] = max(q[i], a[n-i-1]);
    
    for(int i = 0; i < d; i++){
        int l,r; cin >> l >> r; l--; r--;
        cout << max(p[l], q[n-r-1]) << endl;
    }
    return 0;
}