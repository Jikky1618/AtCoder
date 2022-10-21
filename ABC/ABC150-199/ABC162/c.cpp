#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k;
    cin >> k;

    int ans = 0;
    for(int a = 1; a <= k; a++){
        for(int b = 1; b <= k; b++){
            for(int c = 1; c <= k; c++){
                ans += __gcd(__gcd(a,b),c);
            }
        }
    }

    cout << ans << endl;
    return 0;
}