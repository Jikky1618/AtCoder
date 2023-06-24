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
    vector<ll> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < N; i++) cin >> B[i];

    debug(A, B);
    vector<ll> diff(N);
    for(int i = 0; i < N; i++) diff[i] = A[i] - B[i];
    debug(diff);

    // val1 := diff が正の値
    ll val1 = 0;
    for(int i = 0; i < N; i++){
        if(diff[i] > 0) val1 += diff[i];
    }
    // val2 := diff が負の値
    // cnt := diff が負の数かつ, 偶数の数
    ll val2 = 0, cnt = 0;
    for(int i = 0; i < N; i++){
        if(diff[i] < 0){
            val2 += abs(diff[i]);
            if(abs(diff[i]) % 2 == 1) cnt++;
        }
    }

    debug(val1, val2, cnt);
    ll val = val1 * 2 - val2;
    if(val <= 0){
        if(abs(val) < cnt){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }else{
        cout << "No" << endl;
    }
}