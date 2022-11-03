#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<bool> used;
void dfs(int pos, const vector<vector<int>> &graph){
    used[pos] = true;
    for(auto next_pos: graph[pos]){
        if(used[next_pos] == false) dfs(next_pos, graph);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    vector<int> t(n), k(n);
    vector<vector<int>> a(n);
    for(int i = 0; i < n; i++){
        cin >> t[i] >> k[i];
        for(int j = 0; j < k[i]; j++){
            int x; cin >> x; x--;
            a[i].push_back(x);
        }
    }

    used.resize(n);
    dfs(n-1, a);

    ll ans = 0;
    for(int i = 0; i < n; i++) if(used[i]) ans += t[i];

    cout << ans << endl;
    return 0;
}