// 自力で解いた解法(二分探索+差分更新)
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const ll INF = 1LL << 60;

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
    sort(W.begin(), W.end());

    vector<ll> diff(N);
    for(int i = 0; i < N - 1; i++){
        diff[i] = abs(H[i] - H[i + 1]);
    }

    vector<ll> diff2(N);
    for(int i = 0; i < N - 2; i++){
        diff2[i] = abs(H[i] - H[i + 2]);
    }

    ll ans = INF, val = 0;
    for(int i = 1; i < N - 1; i += 2) val += diff[i];

    for(int i = 0; i < N - 1; i++){
        // H[i] とペアになる最適なWの値を見つけ, 答えを更新
        int pos = lower_bound(W.begin(), W.end(), H[i]) - W.begin();
        if(pos == 0){
            ans = min(ans, val + abs(H[i] - W[pos]));
        }else if(pos == M){
            ans = min(ans, val + abs(H[i] - W[pos - 1]));
        }else{
            ans = min({ans, val + abs(H[i] - W[pos - 1]), val + abs(H[i] - W[pos])});
        }

        // valの値を差分更新
        if(i % 2 == 0){
            val -= diff[i + 1];
            val += diff2[i];
        }else{
            val += diff[i - 1];
            val -= diff2[i - 1];
        }
    }
    // H.back() の場合も更新
    int pos = lower_bound(W.begin(), W.end(), H.back()) - W.begin();
    if(pos == 0){
        ans = min(ans, val + abs(H.back() - W[pos]));
    }else if(pos == M){
        ans = min(ans, val + abs(H.back() - W[pos - 1]));
    }else{
        ans = min({ans, val + abs(H.back() - W[pos - 1]), val + abs(H.back() - W[pos])});
    }

    cout << ans << endl;
}