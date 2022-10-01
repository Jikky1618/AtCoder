#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,m;
    cin >> n >> m;
    vector<vector<int>> Graph(n);
    vector<int> a(m),b(m);
    for(int i = 0; i < m; i++){
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
        Graph[a[i]].push_back(b[i]);
        Graph[b[i]].push_back(a[i]);
    }

    int ans = 0;
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(auto x: Graph[i]){
            if(x < i) cnt++;
        }
        if(cnt == 1) ans++;
    }

    cout << ans << endl;
    return 0;
}