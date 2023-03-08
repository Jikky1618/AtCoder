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
    vector<int> V(3);
    for(int i = 0; i < 3; i++) cin >> V[i];

    int b = V[1];
    sort(V.begin(), V.end());
    cout << (b == V[1] ? "Yes" : "No") << endl;
}