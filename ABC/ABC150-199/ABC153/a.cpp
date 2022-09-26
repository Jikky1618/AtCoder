#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int h,a;
    cin >> h >> a;

    int ans = (h + a - 1) / a;

    cout << ans << endl;
    
    return 0;
}