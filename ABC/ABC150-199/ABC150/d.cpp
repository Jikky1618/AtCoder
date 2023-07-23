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
    ll N, M;
    cin >> N >> M;
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // X = 1/2A(2p+1) に条件を変形
    for(int i = 0; i < N; i++) A[i] /= 2;

    vector<ll> A2 = A;
    // 2p + 1 は奇数なので, 2 の倍数の個数は A によってのみ決定する
    int k = 0, cnt = 0;
    bool flag = false; // 半公倍数が構築不可能か
    for(int i = 0; i < N; i++){
        if(i == 0){
            while(A2[i] % 2 == 0) A2[i] /= 2, k++;
        }else{
            cnt = 0;
            while(A2[i] % 2 == 0) A2[i] /= 2, cnt++;
            // 2 で割れる回数が 1 つでも異なるなら構築不可能
            if(cnt != k) flag = true;
        }
    }

    if(flag){
        cout << 0 << endl;
        return 0;
    }

    ll L = 1;
    // 最小公倍数を求める   
    for(int i = 0; i < N; i++){
        L = lcm(L, A[i]);
        // L が途中でバカでかくなる場合があるので, 途中で打ち切りを入れる
        if(M - L < 0) break;
    }

    // 2p + 1 は奇数なので, 半公倍数は L, 3L, 5L, ... となる
    ll ans = (M - L < 0 ? 0 : (M - L) / (2 * L) + 1);
    cout << ans << endl;
}