#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll a, b, x;
    cin >> a >> b >> x;

    auto f = [&](ll N) -> ll {
        if(N < 0) return 0;
        return N / x + 1;
    };

    cout << f(b) - f(a - 1) << endl;
    return 0;
}