#include <bits/stdc++.h>
using namespace std;
using ll = long long;

void dfs(vector<vector<int>> &G, vector<bool> &seen, vector<int> &ans, int pos){
    seen[pos] = true;
    ans.push_back(pos + 1);

    for(auto &&next_pos: G[pos]){
        if(seen[next_pos]) continue;
        dfs(G, seen, ans, next_pos);
        ans.push_back(pos + 1);
    }
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<vector<int>> Graph(N);
    for(int i = 0; i < N - 1; i++){
        int A, B; cin >> A >> B; A--, B--;
        Graph[A].push_back(B);
        Graph[B].push_back(A);
    }
    for(int i = 0; i < N; i++) sort(Graph[i].begin(), Graph[i].end());
    
    vector<bool> seen(N);
    vector<int> ans;
    dfs(Graph, seen, ans, 0);

    for(auto &&i: ans){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}