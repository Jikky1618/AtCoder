#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<int> s(m);
    vector<char> c(m);
    for(int i  = 0; i < m; i++) cin >> s[i] >> c[i];

    for(int i = 0; i <= 999; i++){
        if(to_string(i).size() != n) continue;
        bool flag = true;
        for(int j = 0; j < m; j++){
            if(to_string(i).at(s[j] - 1) != c[j]) flag = false;
        }
        if(flag){
            cout << i << endl;
            return 0;
        }
    }

    cout << -1 << endl;
    return 0;
}