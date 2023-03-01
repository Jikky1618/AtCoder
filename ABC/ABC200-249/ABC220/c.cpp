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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    ll X;
    cin >> X;

    ll A_sum = 0;
    for(int i = 0; i < N; i++) A_sum += A[i];

    ll cycle_cnt = X / A_sum;
    ll val = cycle_cnt * A_sum;
    ll ans = cycle_cnt * N;
    for(int i = 0; i < N; i++){
        val += A[i];
        ans++;
        if(val > X){
            cout << ans << endl;
            return 0;
        }
    }
}