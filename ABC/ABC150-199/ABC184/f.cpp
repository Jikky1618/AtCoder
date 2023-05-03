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
    int N, T;
    cin >> N >> T;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    int X = N / 2, Y = N - X;
    vector<ll> A1(1 << X);
    for(int bit = 0; bit < (1 << X); bit++){
        for(int i = 0; i < X; i++){
            if((bit >> i) & 1) A1[bit] += A[i];
        }
    }
    vector<ll> A2(1 << Y);
    for(int bit = 0; bit < (1 << Y); bit++){
        for(int i = 0; i < Y; i++){
            if((bit >> i) & 1) A2[bit] += A[X + i];
        }
    }
    debug(A1, A2);
    sort(A1.begin(), A1.end());
    sort(A2.begin(), A2.end());

    int ans = 0;
    // T - A1 以下の最大のA2を求める 
    for(int i = 0; i < (1 << X); i++){
        if(A1[i] <= T){
            int val = A1[i] + *prev(upper_bound(A2.begin(), A2.end(), T - A1[i]));
            ans = max(ans, val);
        }
    }

    cout << ans << endl;
}