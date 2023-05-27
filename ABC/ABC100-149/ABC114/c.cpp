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

    int ans = 0;
    auto dfs = [&](auto&& self, ll val, vector<int> used) -> void {
        if(N < val) return;

        bool flag = true;
        for(int i = 0; i < 3; i++){
            if(used[i] == 0) flag = false;
        }

        if(flag) ans++;
        for(int i = 0; i < 3; i++){
            used[i]++;
            self(self, val * 10 + vector<int>{7, 5, 3}[i], used);
            used[i]--;
        }
    };

    dfs(dfs, 0, {0, 0, 0});
    cout << ans << endl;
}