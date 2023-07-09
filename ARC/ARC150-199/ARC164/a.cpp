#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// cf. https://atcoder.jp/contests/abc105/submissions/29624988
vector<int> integer_digits(ll n, int b = 10){
    vector<int> res;
    if(n == 0){
        res.emplace_back(0);
        return res;
    }

    while(n != 0){
        int d = ((n % abs(b)) + abs(b)) % abs(b);
        res.emplace_back(d);
        n = (n - d) / b;
    }

    reverse(res.begin(), res.end());

    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;
    while(T--){
        ll N, K;
        cin >> N >> K;
        // 3 進数表示したときが最小の構成
        vector<int> V = integer_digits(N, 3);
        // 最小の構成数を求める
        int L = 0;
        for(auto v: V) L += v;
        // K が最小の構成数 L 以上で, K と L の偶奇が一致するなら Yes
        cout << (L <= K && L % 2 == K % 2 ? "Yes" : "No") << '\n';
    }
}