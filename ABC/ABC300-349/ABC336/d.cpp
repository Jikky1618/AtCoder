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

    vector<int> l(N);
    l[0] = 1;
    for(int i = 1; i < N; i++){
        l[i] = min(l[i - 1] + 1, A[i]);
    }
    vector<int> r(N);
    r[N - 1] = 1;
    for(int i = N - 1; i > 0; i--){
        r[i - 1] = min(r[i] + 1, A[i - 1]);
    }
    debug(l, r);
    int ans = 0;
    for(int i = 0; i < N; i++) ans = max(ans, min(l[i], r[i]));
    cout << ans << endl;
}