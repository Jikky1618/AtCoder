#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    int ans = (b - 1 + a - 2) / (a - 1);
    cout << ans << endl;
    return 0;
}