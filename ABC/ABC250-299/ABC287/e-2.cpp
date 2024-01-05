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
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<int> ans(N);
    auto dfs = [&](auto&& self, int pos, vector<int> id) -> void {
        // groups[i] := pos 文字目の文字が i である文字列の id
        vector<vector<int>> groups(26);
        for(auto i: id){
            // 文字列 i が pos 文字なら答えは pos
            if(pos == int(S[i].size())){
                ans[i] = pos;
                continue;
            }
            groups[S[i][pos] - 'a'].emplace_back(i);
        }
        // groups ごとに再帰
        for(auto& g: groups){
            if(g.empty()) continue;
            // g の大きさが 1 ならその LCP の最大値は確定
            if(g.size() == 1){
                ans[g[0]] = pos;
            // g の大きさが 2 以上なら再帰
            }else{
                self(self, pos + 1, g);
            }
        }
    };
    vector<int> id(N);
    iota(id.begin(), id.end(), 0);
    dfs(dfs, 0, id);

    for(int i = 0; i < N; i++) cout << ans[i] << '\n';
}