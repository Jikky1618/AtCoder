#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    ll a;
    double b;
    cin >> a >> b;

    // bを整数として扱うために100倍
    // 浮動小数点数型を整数型にキャストする際は切り捨て
    // 正しく丸めるためにキャストする際にllroundで四捨五入
    ll fix_b = llround(b * 100);
    // fix_bの修正分として100で割る
    ll ans = a * fix_b / 100;

    cout << ans << endl;
    return 0;
}