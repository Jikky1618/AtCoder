#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int a, b; cin >> a >> b; a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    int Ans = 0;
    for(int i = 0; i < N; i++){
        int cnt = 0;
        for(auto v: G[i]) if(v < i) cnt++;
        if(cnt == 1) Ans++;
    }

    cout << Ans << endl;
    return 0;
}