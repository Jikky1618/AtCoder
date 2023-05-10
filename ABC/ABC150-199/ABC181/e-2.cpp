#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int INF = (1 << 30) - 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<int> H(N), W(M);
    for(int i = 0; i < N; i++) cin >> H[i];
    for(int i = 0; i < M; i++) cin >> W[i];
    sort(H.begin(), H.end());

    // Hの左右からの累積和を作る
    vector<ll> L(N + 1), R(N + 1);
    for(int i = 2; i < N; i += 2){
        L[i] = L[i - 2] + abs(H[i - 1] - H[i - 2]);
        R[i] = R[i - 2] + abs(H[N - i + 1] - H[N - i]);
    }

    ll ans = INF;
    for(int i = 0; i < M; i++){
        int pos = lower_bound(H.begin(), H.end(), W[i]) - H.begin();
        if(pos % 2 == 0){
            ans = min(ans, L[pos] + R[N - pos - 1] + abs(H[pos] - W[i]));
        }else{
            ans = min(ans, L[pos - 1] + R[N - pos] + abs(H[pos - 1] - W[i]));
        }
    }

    cout << ans << endl;
}