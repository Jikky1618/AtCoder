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

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> h(N);
    for(int i = 0; i < N; i++) cin >> h[i];

    auto check = [&](ll mid) -> bool {
        vector<ll> remain(N);
        for(int i = 0; i < N; i++) remain[i] = max(0LL, h[i] - B * mid);
        ll cnt = 0; // A - Bのダメージを何回与えれば良いかをカウント
        for(int i = 0; i < N; i++){
            cnt += ceil(remain[i], A - B);
        }
        debug(mid, remain, cnt);
        return cnt <= mid;
    };

    ll ok = 1e9 + 1, ng = 0;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}