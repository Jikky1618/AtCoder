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
    ll R, B, x, y;
    cin >> R >> B >> x >> y;

    auto check = [&](ll mid) -> bool {
        // mid 組作るとき, 必ず両方 mid 本を消費
        ll r = R - mid, b = B - mid;
        ll val = r / (x - 1) + b / (y - 1);
        debug(val, mid);
        return r >= 0 && b >= 0 && val >= mid;
    };

    // mid 組以上作れるかで二分探索
    // ng := 花の本数の合計の半分以上は組が作れない
    ll ok = -1, ng = (R + B) / 2 + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    debug(ok, ng);
    cout << ok << endl;
}