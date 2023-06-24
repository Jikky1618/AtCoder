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

    ll val1 = 0, val2 = 0;
    for(int i = 0; i < N; i++){
        if(diff[i] > 0) val1 += diff[i];
        if(diff[i] < 0) val2 += abs(diff[i]) / 2;
    }
    debug(val1, val2);

    cout << (val1 <= val2 ? "Yes" : "No") << endl;
}