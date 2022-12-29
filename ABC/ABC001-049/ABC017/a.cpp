#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    int ans = 0;
    for(int i = 0; i < 3; i++){
        int s, e; cin >> s >> e;
        ans += s * 0.1 * e;
    }

    cout << ans << endl;
    return 0;
}