#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1 << 29;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n),p(n),x(n);
    for(int i = 0; i < n; i++) cin >> a[i] >> p[i] >> x[i];

    int ans = INF; 
    bool flag = false;
    for(int i = 0; i < n; i++){
        if(x[i] - a[i] > 0){
            ans = min(ans,p[i]);
            flag = true;
        }
    }
    
    if(flag) cout << ans << endl;
    else cout << -1 << endl;

    return 0;
}