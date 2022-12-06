#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N,A,B;
    cin >> N >> A >> B;

    auto sum = [&](ll n) -> ll {
        return n * (n + 1) / 2;
    };

    ll s = sum(N);
    ll a = A * sum(N / A);
    ll b = B * sum(N / B);
    ll l = lcm(A,B) * sum(N / lcm(A,B));
    ll ans = (s - a - b + l);

    cout << ans << endl;
    return 0;
}