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
    vector<int> tx(2), ty(2);
    int T, V, N;
    cin >> tx[0] >> ty[0] >> tx[1] >> ty[1] >> T >> V >> N;
    vector<int> X(N), Y(N);
    for(int i = 0; i < N; i++) cin >> X[i] >> Y[i];

    bool flag = false;
    for(int i = 0; i < N; i++){
        long double dist = hypot(tx[0] - X[i], ty[0] - Y[i]) + hypot(X[i] - tx[1], Y[i] - ty[1]);
        if(dist <= T * V) flag = true;
    }

    cout << (flag ? "YES" : "NO") << endl;
}