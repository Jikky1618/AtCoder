#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n),c(n),d(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < n; i++) cin >> d[i];

    vector<int> p(n*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            p[i*n+j] = a[i]+b[j];
        }
    }
    vector<int> q(n*n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            q[i*n+j] = c[i]+d[j];
        }
    }

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());
    bool flag = false;
    for(int i = 0; i < n*n; i++){
        int pos = lower_bound(q.begin(),q.end(),k-p[i]) - q.begin();
        if(pos < n*n && q[pos] == k-p[i]) flag = true;
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}