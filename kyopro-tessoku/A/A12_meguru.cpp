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
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    auto judge = [&](ll mid) -> bool {
        ll res = 0;
        for(int i = 0; i < N; i++){
            res += mid / A[i];
        }
        return (K <= res);
    };

    ll ok = 1e9 + 1, ng = -1;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}