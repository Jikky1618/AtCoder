#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> s(m);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        for(int j = 0; j < k; j++){
            int s_in; cin >> s_in;
            s[i].push_back(s_in - 1);
        }
    }
    vector<int> p(m);
    for(int i = 0; i < m; i++) cin >> p[i];

    int ans = 0;
    // bit全探索
    for(int bit = 0; bit < (1 << n); bit++){
        int sum_lighting = 0;
        for(int i = 0; i < m; i++){
            int cnt = 0;
            for(auto v: s[i]){ // for(int v = 0; v < s[i].size(); v++)
                if((bit >> v) & 1) cnt++;
            }
            // 電球iが点灯する条件
            if(cnt % 2 == p[i]) sum_lighting++;
        }
        // 全ての電球が点灯
        if(sum_lighting == m) ans++;
    }

    cout << ans << endl;
    return 0;
}