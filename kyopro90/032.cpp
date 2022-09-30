#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++) cin >> a[i][j];
    }
    int m; cin >> m;
    vector<int> x(m),y(m);
    for(int i = 0; i < m; i++) cin >> x[i] >> y[i];

    vector<vector<bool>> ng(n + 1,vector<bool>(n + 1));
    for(int i = 0; i < m; i++){
        ng[x[i]][y[i]] = true;
        ng[y[i]][x[i]] = true;
    }
    vector<int> p;
    for(int i = 1; i <= n; i++) p.push_back(i);
    int ans = INF;
    do{
        int time = 0;
        bool can = true;
        for(int i = 0; i < n - 1; i++){
            if(ng[p[i]][p[i + 1]]) can = false;
        }
        for(int i = 0; i < n; i++){
            time += a[p[i] - 1][i];
        }

        if(can){
            ans = min(ans,time);
        }
    }while(next_permutation(p.begin(), p.end()));

    if(ans == INF) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}