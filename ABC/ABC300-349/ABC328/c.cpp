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
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;

    vector<int> acc(N);
    for(int i = 0; i < N - 1; i++) acc[i + 1] = acc[i] + (S[i] == S[i + 1]);

    while(Q--){
        int l, r; cin >> l >> r, l--, r--;
        cout << acc[r] - acc[l] << '\n';
    }
}