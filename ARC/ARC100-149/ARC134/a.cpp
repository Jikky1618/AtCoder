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
    ll N, L, W;
    cin >> N >> L >> W;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = 0;
    // 左端
    ans += ceil(A.front(), W);
    for(int i = 0; i < N - 1; i++){
        ll X = max(A[i + 1] - A[i] - W, 0LL);
        ans += ceil(X, W);
    }
    // 右端
    ans += ceil(L - A.back() - W, W);
    cout << ans << endl;
}