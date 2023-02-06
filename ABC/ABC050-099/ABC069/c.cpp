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
    vector<ll> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];
    
    int d4 = 0, d2 = 0, d = 0;
    for(int i = 0; i < N; i++){
        if(A[i] % 4 == 0) d4++;
        else if(A[i] % 2 == 0) d2++;
        else d++;
    }

    bool flag = false;
    if(d <= d4) flag = true;
    if(d4 + 1 == d && d + d4 == N) flag = true;
    debug(d, d2, d4);

    cout << (flag ? "Yes" : "No") << endl;
}