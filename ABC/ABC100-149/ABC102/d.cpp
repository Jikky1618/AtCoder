#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

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
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<ll> acc(N + 1);
    for(int i = 0; i < N; i++) acc[i + 1] = acc[i] + A[i];

    ll ans = INF;
    // 真ん中の１つを全探索し、 BC = a[0, i)とDE = a[i, N)に分ける
    for(int i = 1; i < N; i++){
        ll PQ = acc[i];
        ll RS = acc[N] - acc[i];
        // 左側で、PQのちょうど半分以上になる区間を二分探索
        int p1 = lower_bound(acc.begin(), acc.end(), PQ / 2) - acc.begin();
        // 右側で、RSのちょうど半分以上になる区間を二分探索
        int p2 = lower_bound(acc.begin(), acc.end(), acc[i] + RS / 2) - acc.begin();
        // p1, p3 の周辺を全探索
        for(int j = p1 - 1; j <= p1 + 1; j++){
            for(int k = p2 - 1; k <= p2 + 1; k++){
                if(0 < j && j < N && 0 < k && k < N){
                    ll P = acc[j];
                    ll Q = acc[i] - acc[j];
                    ll R = acc[k] - acc[i];
                    ll S = acc[N] - acc[k];
                    ll val = max({P, Q, R, S}) - min({P, Q, R, S});
                    ans = min(ans, val);
                }
            }
        }
    }

    cout << ans << endl;
}