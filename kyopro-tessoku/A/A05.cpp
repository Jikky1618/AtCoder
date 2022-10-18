#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,k;
    cin >> n >> k;

    int ans = 0;
    for(int red = 1; red <= n; red++){
        for(int blue = 1; blue <= n; blue++){
            int white = k - red - blue;
            if(1 <= white && white <= n) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}