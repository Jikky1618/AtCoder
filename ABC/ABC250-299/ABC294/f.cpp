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
    ll N, M, K;
    cin >> N >> M >> K;
    vector<int> A(N), B(N), C(M), D(M);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    for(int i = 0; i < M; i++) cin >> C[i] >> D[i];

    auto check = [&](double mid) -> bool {
        vector<double> AB(N), CD(M);
        for(int i = 0; i < N; i++) AB[i] = A[i] - mid * (A[i] + B[i]);
        for(int i = 0; i < M; i++) CD[i] = mid * (C[i] + D[i]) - C[i];
        sort(CD.begin(), CD.end());

        ll cnt = 0;
        for(int i = 0; i < N; i++){
            int j = lower_bound(CD.begin(), CD.end(), AB[i]) - CD.begin();
            cnt += j;
        }

        return cnt >= K;
    };

    // 濃度を二分探索
    // NM通りの砂糖水のうち濃度がmidより濃い砂糖水はK本以上である最大の濃度
    double ng = 1, ok = 0;
    for(int iter = 0; iter < 100; iter++){
        double mid = (ok + ng) / 2;
        if(check(mid)) ok = mid;
        else ng = mid;
    }

    cout << ok * 100 << endl;
}