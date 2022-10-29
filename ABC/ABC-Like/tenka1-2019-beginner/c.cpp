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

    // sb[i]: 区間 [0, i) についての黒の個数
    // sw[i]: 区間 [i, N) についての白の個数
    vector<int> sb(n + 1),sw(n + 1);
    for(int i = 0; i < n; i++){
        if(s[i] == '#') sb[i + 1] = sb[i] + 1;
        else sb[i + 1] = sb[i];
    }
    for(int i = 0; i < n; i++){
        if(s[n-i-1] == '.') sw[i + 1] = sw[i] + 1;
        else sw[i + 1] = sw[i];
    }

    int ans = INF;
    for(int i = 0; i < n; i++){
        ans = min(ans, sb[i] + sw[n-i-1]);
    }
    cout << ans << endl;
    return 0;
}