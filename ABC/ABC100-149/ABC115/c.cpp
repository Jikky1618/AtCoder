#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,k;
    cin >> n >> k;
    vector<int> h(n);
    for(int i = 0; i < n; i++) cin >> h[i];

    sort(h.begin(), h.end());
    int ans = INF;
    for(int i = 0; i < n - k + 1; i++){
        ans = min(ans, h[i + k - 1] - h[i]);
    }

    cout << ans << endl;
    return 0;
}