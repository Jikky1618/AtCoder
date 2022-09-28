#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    double ans = (double)((n + 2 - 1) / 2) / (double)n;
    cout << ans << endl;
    return 0;
}