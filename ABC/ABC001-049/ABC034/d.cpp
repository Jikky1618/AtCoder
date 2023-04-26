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
    vector<int> w(N), p(N);
    for(int i = 0; i < N; i++) cin >> w[i] >> p[i];

    auto check = [&](double mid) -> double {
        vector<double> v;
        for(int i = 0; i < N; i++){
            v.emplace_back(w[i] * (p[i] - mid));
        }
        sort(v.begin(), v.end(), greater<double>());

        double m = 0;
        for(int i = 0; i < K; i++) m += v[i];

        return m >= 0;
    };

    double ng = 100, ok = 0;
    for(int iter = 0; iter < 100; iter++){
        double mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok << endl;
}