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
    int N, P, Q;
    cin >> N >> P >> Q;
    vector<int> D(N);
    for(int i = 0; i < N; i++) cin >> D[i];

    int M = *min_element(D.begin(), D.end());
    int ans = min(P, Q + M);
    cout << ans << endl;
}