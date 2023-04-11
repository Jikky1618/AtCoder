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
    int K;
    cin >> K;

    vector<ll> ans;
    auto dfs = [&](auto &&self, int pos, ll val) -> void {
        ans.emplace_back(val);
        // 制約で最大のルンルン数は10桁
        if(pos >= 10){
            return;
        }

        for(int i = -1; i <= 1; i++){
            int add = (val % 10) + i;
            if(0 <= add && add <= 9){
                self(self, pos + 1, val * 10 + add);
            }
        }
    };

    for(int i = 1; i <= 9; i++){
        dfs(dfs, 1, i);
    }

    sort(ans.begin(), ans.end());
    cout << ans[K - 1] << endl;
}