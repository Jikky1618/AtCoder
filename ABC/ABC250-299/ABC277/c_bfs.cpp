#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    map<int,vector<int>> graph;
    for(int i = 0; i < n; i++){
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }


    set<int> st; // 訪れた場所
    st.insert(1);
    queue<int> que;
    que.push(1);
    while(!que.empty()){
        int pos = que.front(); que.pop();
        for(auto next_pos: graph[pos]){
            if(!st.count(next_pos)){
                st.insert(next_pos);
                que.push(next_pos);
            }
        }
    }

    cout << *max_element(st.begin(),st.end()) << endl;
    return 0;
}