#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

template<class T, class U>
T floor(T x, U y){
    return (x ? x / y : (x + y - 1) / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<ll> T(N), A(N);
    for(int i = 0; i < N; i++) cin >> T[i] >> A[i];

    ll t = 1, a = 1;
    for(int i = 0; i < N; i++){
        ll val = max(ceil(t, T[i]), ceil(a, A[i]));
        t = T[i] * val, a = A[i] * val;
    }

    cout << t + a << endl;
}