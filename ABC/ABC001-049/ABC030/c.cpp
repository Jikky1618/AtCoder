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
    int N, M, X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    

    int ans = 0, time = 0;
    while(1){
        if(ans % 2 == 0){
            auto itr = lower_bound(A.begin(), A.end(), time);
            if(itr == A.end()) break;
            time = *itr + X, ans++;
        }
        if(ans % 2 == 1){
            auto itr = lower_bound(B.begin(), B.end(), time);
            if(itr == B.end()) break;
            time = *itr + Y, ans++;
        }
    }

    cout << ans / 2 << endl;
}