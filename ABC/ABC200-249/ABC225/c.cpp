#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll n,m;
    cin >> n >> m;
    vector<vector<ll>> b(n,vector<ll>(m));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> b[i][j];
        }
    }

    bool flag = true;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m - 1; j++){
            if(b[i][j] % 7 == 0) flag = false;
        }
    }
    
    // 比較用行列c
    vector<vector<ll>> c(n,vector<ll>(m));
    c[0][0] = b[0][0];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            c[i][j] = c[0][0] + 7 * i + j;
        }
    }

    if(flag && b == c) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}