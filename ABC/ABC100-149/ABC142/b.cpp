#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0;i < n; i++) cin >> h[i];

    int ans = 0;
    for(int i = 0;i < n; i++){
        if(k <= h[i]) ans++;
    }

    cout << ans << endl;
    return 0;
}