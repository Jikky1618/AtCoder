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
    int Q;
    cin >> S >> Q;

    auto dfs = [&](auto&& self, ll t, ll k) -> char {
        if(t == 0) return S[k];
        if(k == 0) return (char)((S[0] - 'A' + t) % 3 + 'A');
        return (char)((self(self, t - 1, k / 2) - 'A' + 1 + (k % 2 == 1)) % 3 + 'A');
    };

    while(Q--){
        ll t, k;
        cin >> t >> k, k--;
        cout << dfs(dfs, t, k) << "\n";
    }
}