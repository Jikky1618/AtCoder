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
    int L, Q;
    cin >> L >> Q;

    // woods := 各木材の左端の位置(0, Lは番兵)
    set<int> woods{0, L};
    while(Q--){
        int c, x; cin >> c >> x;
        if(c == 1){
            woods.insert(x);
        }
        if(c == 2){
            auto itr = woods.lower_bound(x);
            int val = *itr - *--itr;
            cout << val << "\n";
        }
    }
}