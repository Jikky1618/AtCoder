#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s,t;
    cin >> n >> s >> t;

    string ans;
    int s_cnt = 0,t_cnt = 0;
    for(int i = 0; i < 2 * n; i++){
        if(i % 2 == 0){
            ans += s[s_cnt];
            s_cnt++;
        }else{
            ans += t[t_cnt];
            t_cnt++;
        }
    }

    cout << ans << endl;
    return 0;
}