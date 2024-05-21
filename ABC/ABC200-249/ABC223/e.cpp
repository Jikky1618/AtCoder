#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template <class T, class U>
T ceil(T x, U y) {
    return (x > 0 ? (x + y - 1) / y : x / y);
}
template <class T, class U>
T floor(T x, U y) {
    return (x > 0 ? x / y : (x - y + 1) / y);
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;

    bool flag = false;
    // 縦 3 つの領域に分ける場合
    // 高さは Y 固定, 幅は貪欲に決定させる
    if(ceil(A, Y) + ceil(B, Y) + ceil(C, Y) <= X) {
        flag = true;
    }
    // 横 3 つの領域に分ける場合
    // 幅は X 固定, 高さは貪欲に決定させる
    if(ceil(A, X) + ceil(B, X) + ceil(C, X) <= Y) {
        flag = true;
    }

    vector<ll> P{A, B, C};
    sort(P.begin(), P.end());
    do {
        // 縦 2 つ, 横 1 つの領域に分ける場合
        // 横 1 つの高さを決める
        ll h1 = ceil(P[0], X);
        // 縦 2 つの高さは Y - h1 に固定して, 幅を貪欲に決定させる
        if(Y - h1 > 0 && ceil(P[1], Y - h1) + ceil(P[2], Y - h1) <= X) {
            flag = true;
        }
        // 横 2 つ, 縦 1 つの領域に分ける場合
        // 縦 1 つの幅を決める
        ll w1 = ceil(P[0], Y);
        // 横 2 つの幅は X - w1 に固定して, 高さを貪欲に決定させる
        if(X - w1 > 0 && ceil(P[1], X - w1) + ceil(P[2], X - w1) <= Y) {
            flag = true;
        }
    } while(next_permutation(P.begin(), P.end()));

    cout << (flag ? "Yes" : "No") << '\n';
}