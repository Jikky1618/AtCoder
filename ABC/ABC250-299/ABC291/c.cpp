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
    int N;
    string S;
    cin >> N >> S;

    set<pair<int, int>> st;
    int x = 0, y = 0;
    st.insert({0, 0});

    bool flag = false;
    for(auto c: S){
        if(c == 'L') x--;
        if(c == 'R') x++;
        if(c == 'D') y--;
        if(c == 'U') y++;

        if(st.count({x, y})) flag = true;
        st.insert({x, y});
    }

    cout << (flag ? "Yes" : "No") << endl;
}