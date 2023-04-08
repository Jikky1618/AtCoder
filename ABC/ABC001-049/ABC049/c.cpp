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

    int N = S.size();
    const vector<string> strs = {"dream", "dreamer", "erase", "eraser"};

    // dp[i] := Tのi番目の文字で矛盾が起きないか 
    vector<int> dp(N + 1);
    dp[0] = 1;

    for(int i = 0; i < N; i++){
        for(auto str: strs){
            int M = str.size();
            if(i + M <= N && dp[i] == 1){
                if(S.substr(i, str.size()) == str) dp[i + M] = 1;
            }
        }
    }

    cout << (dp[N] ? "YES" : "NO") << endl;
}