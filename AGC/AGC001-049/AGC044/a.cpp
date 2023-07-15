#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

using i128 = __int128_t;
using u128 = __uint128_t;
i128 parse(string& s) {
    i128 res = 0;
    for (const auto& c : s)
        if (isdigit(c)) res = 10 * res + c - '0';

    if (s.front() == '-') res *= -1;
    return res;
}

istream& operator>>(istream& is, i128& value) {
    string str;
    is >> str;
    value = parse(str);
    return is;
}

ostream& operator<<(ostream& os, const i128& value) {
    if (!ostream::sentry(os)) return os;
    u128 tmp = value < 0 ? -value : value;
    char buffer[128];
    char* d = end(buffer);

    do {
        d--;
        *d = "0123456789"[tmp % 10];
        tmp /= 10;
    } while (tmp != 0);
    if (value < 0) {
        d--;
        *d = '-';
    }
    int len = end(buffer) - d;
    if (os.rdbuf()->sputn(d, len) != len) {
        os.setstate(ios_base::badbit);
    }

    return os;
}

void solve(){
    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    // 逆から見る
    // memo[val] := val -> 0 にするための最小回数
    map<i128, i128> memo;
    auto dfs = [&](auto&& self, i128 val) -> i128 {
        if(memo.count(val)) return memo[val];
        if(val <= 1) return memo[val] = val * D;
        memo[val] = val * D;
        // 1. A 払い, val が 2 の倍数なら val / 2
        for(int i = -1; i <= 1; i++){
            if((val + i) % 2 == 0){
                memo[val] = min(memo[val], self(self, (val + i) / 2) + abs(i) * D + A);
            }
        }
        // 2. B 払い, val が 3 の倍数なら val / 3
        for(int i = -2; i <= 2; i++){
            if((val + i) % 3 == 0){
                memo[val] = min(memo[val], self(self, (val + i) / 3) + abs(i) * D + B);
            }
        }
        // 3. C 払い, val が 5 の倍数なら val / 5
        for(int i = -4; i <= 4; i++){
            if((val + i) % 5 == 0){
                memo[val] = min(memo[val], self(self, (val + i) / 5) + abs(i) * D + C);
            }
        }

        return memo[val];
    };

    dfs(dfs, N);
    cout << memo[N] << '\n';
}
int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while(T--) solve();
}