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
    for(int i = 0; i < N; i++) cin >> A[i];

    ll ans = 1000;
    for(int i = 0; i < N - 1; i++){
        if(A[i] < A[i + 1]){
            // 株を購入
            ll stock = ans / A[i];
            ans -= stock * A[i];
            // 株を売却
            ans += stock * A[i + 1];
        }
    }

    cout << ans << endl;
}