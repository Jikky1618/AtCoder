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

    vector<ll> P;
    for(int bit = 0; bit < (1 << (N / 2)); bit++){
        ll sum = 0;
        for(int i = 0; i < (N / 2); i++){
            if((bit >> i) & 1) sum += A[i];
        }
        P.push_back(sum);
    }
    vector<ll> Q;
    for(int bit = 0; bit < (1 << (N - N / 2)); bit++){
        ll sum = 0;
        for(int i = 0; i < (N - N / 2); i++){
            if((bit >> i) & 1) sum += A[N / 2 + i];
        }
        Q.push_back(sum);
    }

    sort(P.begin(), P.end());
    sort(Q.begin(), Q.end());

    // Pを全探索
    int p = P.size(), q = Q.size();
    bool flag = false;
    for(int i = 0; i < p; i++){
        ll X = K - P[i];
        // QにXがあるか二分探索
        auto pos = lower_bound(Q.begin(), Q.end(), X) - Q.begin();
        if(pos < q && Q[pos] == X) flag = true;
    }

    cout << (flag ? "Yes" : "No") << endl;
}