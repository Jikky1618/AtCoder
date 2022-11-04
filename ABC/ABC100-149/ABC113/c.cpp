#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cout << fixed << setprecision(20);
    int n,m;
    cin >> n >> m;
    vector<int> p(m),y(m);
    for(int i = 0; i < m; i++){
        cin >> p[i] >> y[i];
        p[i]--;
    }

    vector<vector<int>> vals(n);
    for(int i = 0; i < m; i++) vals[p[i]].push_back(y[i]);

    for(int i = 0; i < n; i++){
        sort(vals[i].begin(), vals[i].end());
        // 今回は不要(Y[i]は全て異なるので)
        vals[i].erase(unique(vals[i].begin(),vals[i].end()),vals[i].end());
    }

    for(int i = 0; i < m; i++){
        int id = lower_bound(vals[p[i]].begin(),vals[p[i]].end(),y[i]) - vals[p[i]].begin();
        printf("%06d%06d\n", p[i] + 1, id + 1);
    }
    return 0;
}