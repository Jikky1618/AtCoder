#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<int> l(3);
    for(int i = 0; i < 3; i++) cin >> l[i];

    sort(l.begin(), l.end());

    int ans = l[0] * l[1] / 2;
    cout << ans << endl;
    return 0;
}