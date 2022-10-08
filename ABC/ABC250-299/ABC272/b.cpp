#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> x(m);
    for(int i = 0; i < m; i++){
        int k; cin >> k;
        x[i].resize(k);
        for(int j = 0; j < k; j++){
            cin >> x[i][j];
        }
    }

    vector<vector<int>> seen(n,vector<int>(n));
    for(int i = 0; i < m; i++){
        for(int j = 0; j < x[i].size(); j++){
            for(int k = j + 1; k < x[i].size(); k++){
                seen[x[i][j] - 1][x[i][k] - 1] = 1;
            }
        }
    }

    bool flag = true;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(seen[i][j] == 0) flag = false;
        }
    }
    
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}