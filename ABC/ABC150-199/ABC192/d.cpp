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
    string X; ll M;
    cin >> X >> M;

    int N = X.size();
    // |X| = 1 の場合分け
    if(N == 1){
        cout << (stoi(X) <= M ? 1 : 0) << endl;
        return 0;
    }

    int d = 0;
    for(auto c: X) d = max(d, c - '0');

    // mid進数の値はM以下か二分探索
    auto check = [&](ll mid) -> bool {
        ll sum = 0;
        for(int i = 0; i < N; i++){
            // 大きいならすぐにfalse
            if(sum > M / mid){
                return false;
            }
            sum *= mid;
            sum += X[i] - '0';
        }

        return sum <= M;
    };

    ll ok = d, ng = M + 1;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok - d << endl;
}