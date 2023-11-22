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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> S(N + 1);
    for(int i = 0; i < N; i++) S[i + 1] = S[i] + A[i];

    map<ll, int> mp;
    ll ans = 0;
    for(int r = 0; r <= N; r++){
        // 今までの区間 [0, l) で S[r] % M が同じものが何個あるかを数える
        // このとき、区間 [l, r) の総和は M の倍数になる
        ans += mp[S[r] % M];
        mp[S[r] % M]++;
    }

    cout << ans << '\n';
}