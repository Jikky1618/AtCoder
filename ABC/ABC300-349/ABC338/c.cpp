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
    int N;
    cin >> N;
    vector<ll> Q(N);
    for(int i = 0; i < N; i++) cin >> Q[i];
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    // 料理 A の個数を全探索
    ll ans = 0, MAX = 1e6 + 1;
    for(ll x = 0; x < MAX; x++){
        // 料理 A を x 個作れるかを全探索
        bool flag = true;
        for(int j = 0; j < N; j++) if(A[j] * x > Q[j]) flag = false;
        if(!flag) break;
        // 料理 B の個数を求める
        ll y = MAX;
        for(int j = 0; j < N; j++){
            if(Q[j] - A[j] * x < 0){
                y = -MAX;
            }else{
                if(B[j] != 0) y = min(y, (Q[j] - A[j] * x) / B[j]);
            }
        }
        ans = max(ans, x + y);
    }

    cout << ans << endl;
}