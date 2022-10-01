#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m; cin >> n >> m;
    vector<int> a(m),b(m);
    for(int i = 0; i < m; i++) cin >> a[i] >> b[i];
    int k; cin >> k;
    vector<int> c(k),d(k);
    for(int i = 0; i < k; i++) cin >> c[i] >> d[i];

    int ans = 0;
    for(int bit = 0; bit < (1 << k); bit++){
        vector<int> Bowl(n);
        for(int i = 0; i < k; i++){
            if((bit >> i) & 1){
                Bowl[c[i] - 1]++;
            }else{
                Bowl[d[i] - 1]++;
            }
        }

        int cnt = 0;
        for(int i = 0; i < m; i++){
            if(Bowl[a[i] - 1] && Bowl[b[i] - 1]) cnt++;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}