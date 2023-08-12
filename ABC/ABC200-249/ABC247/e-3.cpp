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
    int N, X, Y;
    cin >> N >> X >> Y;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    // 累積 Max, 累積 Min
    vector<int> M(N + 1), m(N + 1, 1e9);
    for(int i = 0; i < N; i++) M[i + 1] = max(M[i], A[i]);
    for(int i = 0; i < N; i++) m[i + 1] = min(m[i], A[i]);
    debug(M, m);

    ll ans = 0;
    int posX = -1, posY = -1, B = -1;
    for(int i = 0; i < N; i++){
        if(A[i] == X) posX = i;
        if(A[i] == Y) posY = i;
        if(A[i] < Y || X < A[i]) B = i;
        ans += max(min(posX, posY) - B, 0);
    }

    cout << ans << endl;
}