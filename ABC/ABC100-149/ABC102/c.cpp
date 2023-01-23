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
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i], A[i] -= (i + 1);

    // マンハッタン距離の差の総和を最小 -> 中央値
    sort(A.begin(), A.end());
    int b = 0;
    if(N % 2 == 0){
        b = (A[N/2-1] + A[N/2]) / 2;
    }else{
        b = A[N/2];
    }

    ll ans = 0;
    for(int i = 0; i < N; i++){
        ans += abs(A[i] - b);
    }

    cout << ans << endl;
}