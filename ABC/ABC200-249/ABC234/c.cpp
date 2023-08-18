#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// num を r 進数表記したときの桁の配列を返す
vector<int> digits_convert(ll num, int r = 10) {
    vector<int> res;
    // corner case: num = 0
    if (num == 0) {
        res.emplace_back(0);
        return res;
    }
    // mod |r| を取れば最下位桁順に決定していく
    while (num != 0) {
        int d = (num % abs(r)) + (num < 0 ? abs(r) : 0);
        res.emplace_back(d);
        num = (num - d) / r;
    }
    reverse(res.begin(), res.end());
    return res;
}

// r 進表記で上位桁から順に digits が並んだ数の値を返す．
ll integer_convert(vector<int>& digits, int r = 10) {
    int N = int(digits.size());

    ll res = 0, base = 1;
    for (int i = N - 1; i >= 0; i--) {
        res += digits[i] * base;
        base *= r;
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll K;
    cin >> K;
    auto d = digits_convert(K, 2);
    string ans = "";
    for(auto e: d){
        if(e == 0){
            ans += "0";
        }else{
            ans += "2";
        }
    }

    cout << ans << endl;
}