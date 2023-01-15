#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    stack<string> st;
    while(Q--){
        int q; cin >> q;

        if(q == 1){
            string x; cin >> x;
            st.push(x);
        }
        if(q == 2){
            cout << st.top() << "\n";
        }
        if(q == 3){
            st.pop();
        }
    }
}