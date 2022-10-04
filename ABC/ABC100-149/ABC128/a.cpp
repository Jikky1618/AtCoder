#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,p;
    cin >> a >> p;
    p += a * 3;

    int ans = p / 2;
    cout << ans << endl;
    return 0;
}