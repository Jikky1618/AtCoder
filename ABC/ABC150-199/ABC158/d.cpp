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
    string S;
    int Q;
    cin >> S >> Q;

    deque<char> deq;
    for(auto c: S) deq.push_back(c);

    bool rev = false;
    while(Q--){
        int type; cin >> type;
        if(type == 1){
            rev = !rev;
        }
        if(type == 2){
            int F; char C; cin >> F >> C;
            if(F == 1) rev ? deq.push_back(C) : deq.push_front(C);
            if(F == 2) rev ? deq.push_front(C) : deq.push_back(C);
        }
    }

    string ans = "";
    for(auto e: deq) ans += e;
    if(rev) reverse(ans.begin(), ans.end());

    cout << ans << endl;
}