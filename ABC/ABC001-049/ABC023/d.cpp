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
    vector<ll> H(N), S(N);
    for(int i = 0; i < N; i++) cin >> H[i] >> S[i];

    auto check = [&](ll mid) -> bool {
        // 高度midまでに全ての風船を割ることができるかを判定
        vector<ll> t(N); // 風船iを割るまでの制限時間
        for(int i = 0; i < N; i++){
            if(mid < H[i]) return false; // 既に高度mid以上にあるならfalse
            t[i] = (mid - H[i]) / S[i];
        }
        sort(t.begin(), t.end());
        for(int i = 0; i < N; i++) if(t[i] < i) return false;
        return true;
    };

    // ペナルティの最小値を二分探索
    ll ng = -1, ok = INF;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }
    
    cout << ok << endl;
}