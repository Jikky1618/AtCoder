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
    int N, T, M;
    cin >> N >> T >> M;
    
    vector<vector<int>> G(N);
    for(int i = 0; i < M; i++){
        int A, B; cin >> A >> B, A--, B--;
        G[A].emplace_back(B);
        G[B].emplace_back(A);
    }

    debug(G);
    // T = 2 の場合だと, bit 全探索 -> DFS でチーム分け
    int ans = 0;
    vector<int> seen1(N);
    vector<set<int>> t(T);
    auto dfs = [&](auto&& self, int pos) -> void {
        if(pos == N){
            // 空のチームが 1 つもなければ ans++
            for(int i = 0; i < T; i++) if(t[i].empty()) return;
            ans++;
            return;
        }

        for(int i = 0; i < T; i++){
            // pos を入れた新しいチームを 1 つ「だけ」作成
            if(t[i].empty()){
                t[i].insert(pos);
                self(self, pos + 1);
                t[i].erase(pos);
                break;
            }

            // 既にあるチームに pos を追加する
            bool flag = true;
            for(auto ng: G[pos]){
                if(t[i].count(ng)) flag = false;
            }
            // 相性が悪い人がいなければ追加
            if(flag){
                t[i].insert(pos);
                self(self, pos + 1);
                t[i].erase(pos);
            }
        }
    };
    
    dfs(dfs, 0);
    cout << ans << endl;
}