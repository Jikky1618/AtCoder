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
    vector<int> A(N), B(N), C(N), D(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];
    for(int i = 0; i < N; i++) cin >> C[i];
    for(int i = 0; i < N; i++) cin >> D[i];

    vector<int> P, Q;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            P.push_back(A[i] + B[j]);
            Q.push_back(C[i] + D[j]);
        }
    }

    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());
    // Pを全探索
    bool flag = false;
    int p = P.size(), q = Q.size();
    for(int i = 0; i < p; i++){
        int X = K - P[i];
        // QにXがあるか二分探索
        auto pos = lower_bound(Q.begin(), Q.end(), X) - Q.begin();
        if(pos < q && Q[pos] == X) flag = true;
    }

    cout << (flag ? "Yes" : "No") << endl;
}