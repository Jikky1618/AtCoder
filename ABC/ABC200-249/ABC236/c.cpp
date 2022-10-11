#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<string> s(n),t(m);
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < m; i++) cin >> t[i];

    int cnt = 0;
    vector<bool> ans(n);
    for(int i = 0; i < n; i++){
        if(s[i] == t[cnt]){
            ans[i] = true;
            cnt++;
        }else{
            ans[i] = false;
        }
    }

    for(int i = 0; i < n; i++){
        if(ans[i]){
            cout << "Yes" << endl;
        }else{
            cout << "No" << endl;
        }
    }

    return 0;
}