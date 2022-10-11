#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> w(n);
    for(int i = 0; i < n; i++) cin >> w[i];

    int ans = INF;
    for(int t = 0; t < n; t++){
        int s1 = 0, s2 = 0;
        for(int i = 0; i < n; i++){
            if(i <= t) s1 += w[i];
            else s2 += w[i];
        }
        ans = min(ans, abs(s1 - s2));
    }

    cout << ans << endl;
    return 0;
}