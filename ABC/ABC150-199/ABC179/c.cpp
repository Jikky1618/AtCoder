#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    // Aを全探索
    int ans = 0;
    for(int a = 1; a <= n; a++){
        // AB < N を満たすB
        // B = (N - 1) / A
        ans += (n - 1) / a;
    }

    cout << ans << endl;
}