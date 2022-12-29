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

    vector<int> val = {0,0,1,0,1,2,3,0,1,0};
    int ans = 0;
    for(int i = 0; i < n; i++){
        ans += val[a[i]];
    }

    cout << ans << endl;
    return 0;
}