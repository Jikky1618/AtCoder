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
    vector<int> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];

    // mid 日目に飲む薬が K 錠以下かを判定
    auto check = [&](int mid) -> bool { 
        ll val = 0;
        for(int i = 0; i < N; i++){
            if(mid <= A[i]) val += B[i];
        }
        debug(val, mid);
        return val <= K;
    };
    // 二分探索
    int ok = 1e9 + 1, ng = 0;
    while(ok - ng > 1){
        int mid = (ok + ng) / 2;
        (check(mid) ? ok : ng) = mid;
    }

    debug(ok, ng);
    cout << ok << endl;
}