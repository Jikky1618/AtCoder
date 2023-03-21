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
    int N, Q;
    cin >> N >> Q;

    set<int> st1, st2;
    for(int i = 1; i <= N; i++) st1.insert(i);

    while(Q--){
        int type; cin >> type;
        if(type == 1){
            st2.insert(*st1.begin());
            st1.erase(*st1.begin());
        }
        if(type == 2){
            int x; cin >> x;
            st2.erase(x);
        }
        if(type == 3){
            cout << *st2.begin() << "\n";
        }
    }
}