#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    int ans = 0, Min = INF;
    for(int i = 0; i < n; i++){
        if(Min >= p[i]) ans++;
        Min = min(Min, p[i]);
    }

    cout << ans << endl;
    return 0;
}