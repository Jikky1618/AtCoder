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
    cin >> N;
    string S;
    cin >> S;

    stack<string> stk;
    stk.push("");
    for(int i = 0; i < N; i++){
        if(S[i] == '(') stk.push("(");
        if('a' <= S[i] && S[i] <= 'z'){
            stk.top() += S[i];
        }
        if(S[i] == ')'){
            if(stk.top()[0] == '('){
                stk.pop();
            }else{
                stk.top() += ')';
            }
        }
    }
    debug(stk);

    vector<string> V;
    while(!stk.empty()){
        V.emplace_back(stk.top());
        stk.pop();
    }

    reverse(V.begin(), V.end());

    string ans = "";
    for(unsigned i = 0; i < V.size(); i++){
        ans += V[i];
    }

    cout << ans << endl;
}