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

    vector<string> ans;
    auto dfs = [&](auto &&self, int pos, char m = 'a', string w = "") -> void {
        if(pos == N){
            ans.emplace_back(w);
            return;
        }

        for(char c = 'a'; c <= m; c++){
            if(c == m){
                self(self, pos + 1, (char)(m + 1), w + c);
            }else{
                self(self, pos + 1, m, w + c);
            }
        }
    };

    dfs(dfs, 0);
    for(auto w: ans) cout << w << endl;
}