#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

template<class T, class U>
T floor(T x, U y){
    return (x ? x / y : (x + y - 1) / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    sort(B.begin(), B.end());
    // mid 以下の値が K 個以上かを二分探索
    // この条件を満たす最も小さい値の1つ前の値が答え
    auto check = [&](ll mid) -> bool {
        int cnt = 0;
        // A の要素を全探索
        for(int i = 0; i < N; i++){
            // A[i] * B[pos] <= mid となる最大の pos を二分探索
            int pos = lower_bound(B.begin(), B.end(), ceil(mid, A[i])) - B.begin();
            cnt += pos;
            debug(pos, ceil(mid, A[i]));
        }
        
        debug(mid, cnt);
        return K <= cnt;
    };

    ll ok = ll(1e18) + 1, ng = 0;
    debug(ok, ng);
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }
    debug(ok, ng);
    cout << ng << endl;
}