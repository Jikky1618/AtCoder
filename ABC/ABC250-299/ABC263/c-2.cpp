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
    int N, M;
    cin >> N >> M;
    
    vector<int> ans;
    auto dfs = [&](auto &&self, int pos, int val) -> void {
        if(pos == N){
            for(int i = 0; i < N; i++){
                cout << ans[i] << " \n"[i == N - 1];
            }
            return;
        }

        for(int i = val + 1; i <= M; i++){
            ans.push_back(i);
            self(self, pos + 1, i);
            ans.pop_back();
        }
    };

    dfs(dfs, 0, 0);
}