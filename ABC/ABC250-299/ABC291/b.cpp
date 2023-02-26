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
    vector<int> X(5 * N);
    for(int i = 0; i < 5 * N; i++) cin >> X[i];

    sort(X.begin(), X.end());

    int sum = 0;
    for(int i = N; i < 4 * N; i++) sum += X[i];

    double ans = (double)sum / (3 * N);
    cout << ans << endl; 
}