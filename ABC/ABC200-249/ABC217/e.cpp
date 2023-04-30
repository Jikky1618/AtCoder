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

    deque<int> A;
    multiset<int> st;
    while(Q--){
        int t; cin >> t;
        if(t == 1){
            int x; cin >> x;
            A.emplace_back(x);
        }
        if(t == 2){
            if(st.empty()){
                cout << A.front() << '\n';
                A.pop_front();
            }else{
                cout << *st.begin() << '\n';
                st.erase(st.begin());
            }
        }
        if(t == 3){
            for(auto e: A) st.insert(e), A.pop_front();
        }
    }
}