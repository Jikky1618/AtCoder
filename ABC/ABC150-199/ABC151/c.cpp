#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<pair<int,string>> p(m);
    for(int i = 0; i < m; i++) cin >> p[i].first >> p[i].second;

    vector<bool> ac(n);
    vector<int> wa(n);
    for(int i = 0; i < m; i++){
        if(!ac[p[i].first - 1]){
            if(p[i].second == "WA"){
                wa[p[i].first - 1]++;
            }else{
                ac[p[i].first - 1] = true;
            }
        }
    }

    int ans_ac = 0,ans_wa = 0;
    for(int i = 0; i < n; i++){
        if(ac[i]){
            ans_ac++;
            ans_wa += wa[i];
        }
    }

    cout << ans_ac << " " << ans_wa << endl;
    return 0;
}