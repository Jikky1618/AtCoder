#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n,q;
    cin >> n >> q;

    map<int, set<int>> graph;
    for(int i = 0; i < q; i++){
        int t,a,b; cin >> t >> a >> b; a--; b--;
        if(t == 1){
            graph[a].insert(b);
        }
        if(t == 2){
            graph[a].erase(b);
        }
        if(t == 3){
            if(graph[a].count(b) && graph[b].count(a)){
                cout << "Yes" << endl;
            }else{
                cout << "No" << endl;
            }
        }
    }

    return 0;
}