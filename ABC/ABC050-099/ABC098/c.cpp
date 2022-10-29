#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    // se: 右から東に向いている人の累積和
    // sw: 左から西に向いている人の累積和
    vector<int> se(n + 1), sw(n + 1);
    for(int i = 0; i < n; i++){
        if(s[i] == 'W') sw[i + 1] = sw[i] + 1;
        else sw[i + 1] = sw[i];
    }
    for(int i = 0; i < n; i++){
        if(s[n-i-1] == 'E') se[i + 1] = se[i] + 1;
        else se[i + 1] = se[i]; 
    }

    int ans = INF;
    for(int i = 0; i < n; i++){
        ans = min(ans, sw[i]+se[n-i-1]);
    }
    cout << ans << endl;
    return 0;
}