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

    auto judge = [&](long double x) -> bool {
        double f = x * x * x + x;
        return (N <= f);
    };

    long double ok = N, ng = -1;
    while(ok - ng > 0.001){
        long double mid = (ok + ng) / 2.0;
        if(judge(mid)) ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}