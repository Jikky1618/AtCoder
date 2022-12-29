#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;

    int ans = INF;
    for(int i = 1; i <= n; i++){
        int j = n / i;
        int cnt = abs(i - j) + n - (i * j);
        ans = min(ans, cnt);
    }

    cout << ans << endl;
    return 0;
}