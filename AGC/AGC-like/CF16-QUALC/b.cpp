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
    int K, T;
    cin >> K >> T;
    vector<int> A(T);
    for(int i = 0; i < T; i++) cin >> A[i];

    int sum = 0;
    for(int i = 0; i < T; i++) sum += A[i];

    int Max = *max_element(A.begin(), A.end());
    int other = sum - Max;

    int ans = max(0, Max - other - 1);
    cout << ans << endl;
}