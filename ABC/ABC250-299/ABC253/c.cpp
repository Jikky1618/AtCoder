#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int Q;
    cin >> Q;

    multiset<int> st;
    while(Q--){
        int type; cin >> type;
        if(type == 1){
            int x; cin >> x;
            st.insert(x);
        }
        if(type == 2){
            int x, c; cin >> x >> c;
            for(int i = 0; i < c; i++){
                if(st.find(x) == st.end()) break;
                st.erase(st.find(x));
            }
        }
        if(type == 3){
            cout << *st.rbegin() - *st.begin() << endl;
        }
    }
}