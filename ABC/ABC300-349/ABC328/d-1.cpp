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
    cin >> S;

    stack<char> stk;
    for(auto c: S){
        stk.emplace(c);
        while(stk.size() >= 3){
            char c1 = stk.top(); stk.pop();
            char c2 = stk.top(); stk.pop();
            char c3 = stk.top(); stk.pop();
            if(c1 == 'C' && c2 == 'B' && c3 == 'A'){
                continue;
            }
            stk.emplace(c3);
            stk.emplace(c2);
            stk.emplace(c1);
            break;
        }
    }

    string ans = "";
    while(!stk.empty()){
        ans += stk.top();
        stk.pop();
    }

    reverse(ans.begin(), ans.end());
    cout << ans << endl;
}