#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MOD = 998244353;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector<char> c(K);
    vector<int> k(K);
    for(int i = 0; i < K; i++) cin >> c[i] >> k[i], k[i]--;

    vector<int> A(N, -1);
    for(int i = 0; i < K; i++) A[k[i]] = i;

    debug(A);
    vector<int> B(N);
    for(int i = 0; i < K; i++){
        if(c[i]  == 'L'){
            // 右から見て, A[j] が i になるまで,  i を置くことができる
            for(int j = N - 1; j >= 0; j--){
                if(A[j] == i) break;
                if(A[j] == -1) B[j]++;
            }
        }
        if(c[i] == 'R'){
            // 左から見て, A[j] が i になるまで, i を置くことができる
            for(int j = 0; j < N; j++){
                if(A[j] == i) break;
                if(A[j] == -1) B[j]++;
            }
        }
    }
    debug(B);
    ll ans = 1;
    for(int i = 0; i < N; i++){
        ans *= max(1, B[i]);
        ans %= MOD;
    }

    cout << ans << endl;
}