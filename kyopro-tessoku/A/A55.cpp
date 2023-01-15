#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    set<int> st;
    while(Q--){
        int q, x; cin >> q >> x;
        if(q == 1){
            st.insert(x);
        }
        if(q == 2){
            st.erase(x);
        }
        if(q == 3){
            auto itr = st.lower_bound(x);
            cout << (itr == st.end() ? -1 : *itr) << "\n";
        }
    }
}
