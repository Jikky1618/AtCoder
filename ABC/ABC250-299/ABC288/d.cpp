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

    // Aをmod Kで分けたグループの累積和
    vector S(K, vector<int>(N + 1));
    for(int i = 0; i < K; i++){
        for(int j = 0; j < N; j++){
            S[i][j + 1] = S[i][j] + (j % K == i ? A[j] : 0);
        }
    }

    int Q; cin >> Q;
    while(Q--){
        int l, r; cin >> l >> r, l--;
        // K個のグループの[l, r)の総和が全て等しければ良い数列
        bool flag = true;
        int val = S[0][r] - S[0][l];
        for(int i = 0; i < K; i++){
            int val2 = S[i][r] - S[i][l];
            if(val2 != val) flag = false;
        }

        cout << (flag ? "Yes" : "No") << '\n';
    }
}