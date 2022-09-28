#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> a_xy(n);
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        for(int j = 0; j < a; j++){
            int x,y; cin >> x >> y;
            pair<int,int> xy = make_pair(x - 1,y);
            a_xy[i].push_back(xy);
        }
    }

    int ans = 0;
    // 人の正直者/不親切な人の集合をbit全探索
    // bit: 人の正直者/不親切な人の集合を表す
    for(int bit = 0; bit < (1 << n); bit++){
        // 矛盾があるかどうかのflag
        bool check = true;
        // n人について
        for(int i = 0; i < n; i++){
            // bitのi桁目は1ではないかどうか -> bitにi人目は不親切な人かどうか
            if(!((bit >> i) & 1)) continue;
            // i人目の全ての証言について
            for(auto p: a_xy[i]){
                int x = p.first; // x人目は
                int y = p.second; // 1:「正直者」, 0: 「不親切な人」と証言
                // 証言と実際の人が矛盾していたらfalse
                // 「正直者」なのに不親切な人なら矛盾
                if(y == 1 && !((bit >> x) & 1)) check = false;
                // 「不親切な人」なのに正直者なら矛盾
                if(y == 0 && ((bit >> x) & 1)) check = false;
            }
        }
        if(check) ans = max(ans,__builtin_popcount(bit));
    }

    cout << ans << endl;
    return 0;
}