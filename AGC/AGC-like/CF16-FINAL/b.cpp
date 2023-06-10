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

    auto check = [&](ll mid) -> bool {
        ll sum = mid * (mid + 1) / 2;
        for(int i = mid; i >= 1; i--){
            if(sum - i >= N) sum -= i;
        }

        return sum == N;
    };

    // 二分探索
    int ng = 0, ok = N;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    vector<int> ans;
    ll val = ok * (ok + 1) / 2;
    for(int i = ok; i >= 1; i--){
        if(val - i >= N){
            val -= i; 
        }else{
            ans.emplace_back(i);
        }
    }

    for(auto e: ans){
        cout << e << '\n';
    }
}