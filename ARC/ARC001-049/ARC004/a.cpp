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
    vector<int> x(N), y(N);
    for(int i = 0; i < N; i++) cin >> x[i] >> y[i];

    double ans = 0;
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            double dist = hypot(abs(x[i] - x[j]), abs(y[i] - y[j]));
            ans = max(ans, dist);
        }
    }

    cout << ans << endl;
}