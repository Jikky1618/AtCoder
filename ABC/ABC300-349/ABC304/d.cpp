#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    int W, H, N;
    cin >> W >> H >> N;
    vector<int> p(N), q(N);
    for(int i = 0; i < N; i++) cin >> p[i] >> q[i];
    int A;
    cin >> A;
    vector<int> a(A);
    for(int i = 0; i < A; i++) cin >> a[i];
    a.emplace_back(W); // 番兵
    int B;
    cin >> B;
    vector<int> b(B);
    for(int i = 0; i < B; i++) cin >> b[i];
    b.emplace_back(H); // 番兵

    map<pair<int, int>, int> mp;
    for(int i = 0; i < N; i++){
        ll x = lower_bound(a.begin(), a.end(), p[i]) - a.begin();
        ll y = lower_bound(b.begin(), b.end(), q[i]) - b.begin();
        mp[{x, y}]++;
    }
    debug(mp);

    int m = N, M = 0;
    for(auto [key, val]: mp){
        m = min(m, val), M = max(M, val);
    }
    if((ll)mp.size() < (ll)(A + 1) * (B + 1)){
        m = 0;
    }

    cout << m << " " << M << endl;
}