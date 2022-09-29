#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> a(n),b(m);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++) cin >> b[i];

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = INF;
    int pos_a = 0,pos_b = 0;
    while(pos_a < n && pos_b < m){
        ans = min(ans, abs(a[pos_a] - b[pos_b]));
        if(a[pos_a] < b[pos_b]) pos_a++;
        else pos_b++;
    }

    cout << ans << endl;
    return 0;
}