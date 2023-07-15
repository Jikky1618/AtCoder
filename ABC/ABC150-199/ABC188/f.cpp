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
    ll X, Y;
    cin >> X >> Y;

    // 逆から見て, メモ化再帰
    // memo[val] := val から X にするための最小回数とする
    // 1. val++, 2. val--, 3. val が偶数なら val / 2
    map<ll, ll> memo;
    auto dfs = [&](auto&& self, ll val) -> ll {
        if(memo.count(val)) return memo[val];
        // val <= X のとき, 増やす操作は1種類のみなので答えは X - val
        if(val <= X) return memo[val] = X - val;
        memo[val] = val - X;
        // Y を半分にする(Y が偶数)
        // Y を +1 か -1 にしてから半分(Y が奇数)となる
        if(val % 2 == 0){
            memo[val] = min(memo[val], self(self, val / 2) + 1);
        }else{
            memo[val] = min(memo[val], self(self, (val + 1) / 2) + 2);
            memo[val] = min(memo[val], self(self, (val - 1) / 2) + 2);
        }

        return memo[val];
    };

    dfs(dfs, Y);
    debug(memo);
    cout << memo[Y] << endl;
}