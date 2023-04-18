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
    int X, Y, Z, K;
    cin >> X >> Y >> Z >> K;
    vector<ll> A(X), B(Y), C(Z);
    for(int i = 0; i < X; i++) cin >> A[i];
    for(int i = 0; i < Y; i++) cin >> B[i];
    for(int i = 0; i < Z; i++) cin >> C[i];

    vector<ll> BC;
    for(int i = 0; i < Y; i++){
        for(int j = 0; j < Z; j++){
            BC.emplace_back(B[i] + C[j]);
        }
    }

    sort(BC.begin(), BC.end());

    auto check = [&](ll mid) -> bool {
        int N = BC.size();
        ll cnt = 0;
        for(int i = 0; i < X; i++){
            int idx = lower_bound(BC.begin(), BC.end(), mid - A[i]) - BC.begin();
            cnt += N - idx;
        }
        // midより大きい組合せがK個以上か
        return K <= cnt;
    };

    // K番目の値(大きい組合せがK個以上の最小値)を二分探索
    // ok = 0: 小さい値の方がそれより大きい組合せは多い
    // ng = INF: 大きい値の方がそれより大きい組合せは少ない
    ll ok = 0, ng = INF;
    while(ng - ok > 1){
        ll mid = (ng + ok) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    reverse(BC.begin(), BC.end()); // 降順にソート

    vector<ll> ans;
    for(int i = 0; i < X; i++){
        for(auto bc: BC){
            if(ok <= A[i] + bc) ans.emplace_back(A[i] + bc);
            else break;
        }
    }

    sort(ans.begin(), ans.end(), greater<ll>());
    for(int i = 0; i < K; i++){
        cout << ans[i] << "\n";
    }
}