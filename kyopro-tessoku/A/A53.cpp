#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    priority_queue<int, vector<int>, greater<int>> pq;
    while(Q--){
        int q; cin >> q;
        if(q == 1){
            int x; cin >> x;
            pq.push(x);
        }
        if(q == 2){
            cout << pq.top() << endl;
        }
        if(q == 3){
            pq.pop();
        }
    }
}