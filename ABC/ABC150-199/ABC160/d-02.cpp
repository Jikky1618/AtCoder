#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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
    int N, X, Y;
    cin >> N >> X >> Y, X--, Y--;

    vector<int> ans(N);
    for(int i = 0; i < N; i++){
        for(int j = i + 1; j < N; j++){
            int dist = INF;

            // use X -> Y
            dist = min(dist, abs(X - i) + abs(Y - j) + 1);

            // not use X -> Y
            dist = min(dist, j - i);

            ans[dist]++;
        }
    }

    for(int k = 1; k < N; k++){
        cout << ans[k] << "\n";
    }
}