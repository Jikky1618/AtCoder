#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> l(n);
    for(int i = 0; i < n; i++) cin >> l[i];

    vector<int> bound(n + 1);
    bound[0] = 0;
    for(int i = 0; i < n; i++) bound[i + 1] = bound[i] + l[i];

    int ans = 0;
    for(int i = 0; i <= n; i++){
        if(bound[i] > x) break;
        ans++;
    }

    cout << ans << endl;
    return 0;
}