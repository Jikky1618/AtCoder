#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,d;
    cin >> n >> d;

    int ans = (n + 2 * d) / (2 * d + 1);
    cout << ans << endl;
    return 0;
}