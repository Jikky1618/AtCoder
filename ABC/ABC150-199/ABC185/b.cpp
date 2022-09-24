#include <bits/stdc++.h>
using namespace std;
using ll = long long;

bool can = true;
void check(int num){
    if(num <= 0) can = false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m,t;
    cin >> n >> m >> t;
    vector<int> a(m),b(m);
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
    
    int now = n;
    // Start => a[i]
    now -= a[0];
    check(now);
    for(int i = 0; i < m; i++){
        // b[i] => a[i+1]
        if(i != 0) now -= a[i] - b[i - 1];
        check(now);
        // recharging
        now = min(n,now + b[i] - a[i]);
    }
    // b[i] => goal
    now -= t - b.back();
    check(now);

    if(can) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}