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

    multiset<ll> st;
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            ll x; cin >> x;
            st.insert(x);
        }
        if(t == 2){
            ll x, k; cin >> x >> k;
            auto itr = st.upper_bound(x);
            bool none = false;
            for(int i = 0; i < k; i++){
                if(itr == st.begin()) none = true;
                if(none) break;
                itr--;
            }
            cout << (none ? -1 : *itr) << "\n";
        }
        if(t == 3){
            ll x, k; cin >> x >> k;
            auto itr = st.lower_bound(x);
            bool none = (itr == st.end());
            for(int i = 0; i < k - 1; i++){
                if(none) break;
                itr++;
                if(itr == st.end()) none = true;
            }
            cout << (none ? -1 : *itr) << "\n";
        }
    }
}