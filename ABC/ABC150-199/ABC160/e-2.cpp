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
    int X, Y, A, B, C;
    cin >> X >> Y >> A >> B >> C;
    vector<int> p(A), q(B), r(C);
    for(int i = 0; i < A; i++) cin >> p[i];
    for(int i = 0; i < B; i++) cin >> q[i];
    for(int i = 0; i < C; i++) cin >> r[i];

    sort(p.begin(), p.end(), greater<int>());
    sort(q.begin(), q.end(), greater<int>());

    vector<int> eat;
    for(int i = 0; i < X; i++) eat.emplace_back(p[i]);
    for(int i = 0; i < Y; i++) eat.emplace_back(q[i]);
    for(int i = 0; i < C; i++) eat.emplace_back(r[i]);
    sort(eat.begin(), eat.end(), greater<int>());

    ll ans = 0;
    for(int i = 0; i < X + Y; i++) ans += eat[i];

    cout << ans << endl;
}