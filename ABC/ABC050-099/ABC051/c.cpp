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
    int sx, sy, tx, ty;
    cin >> sx >> sy >> tx >> ty;

    // 差を計算
    int dx = tx - sx, dy = ty - sy;

    // path1
    cout << string(dy, 'U') << string(dx, 'R');
    // path2
    cout << string(dy, 'D') << string(dx, 'L');
    // path3
    cout << 'L' << string(dy + 1, 'U') << string(dx + 1, 'R') << 'D';
    // path4
    cout << 'R' << string(dy + 1, 'D') << string(dx + 1, 'L') << 'U' << endl;
}