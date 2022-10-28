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
    vector<int> l(d), r(d);
    for(int i = 0; i < d; i++) cin >> l[i] >> r[i];

    // 累積max
    vector<int> p(n+1),q(n+1);
    for(int i = 0; i < n; i++) p[i+1] = max(p[i], a[i]);
    for(int i = n ; i > 0; i--) q[i-1] = max(q[i], a[i-1]);
    
    for(int i = 0; i < d; i++){
        cout << max(p[l[i]-1], q[r[i]]) << endl;
    }

    return 0;
}