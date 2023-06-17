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
    vector<int> A(64);
    for(int i = 0; i < 64; i++) cin >> A[i];

    unsigned long long ans = 0;
    for(int i = 0; i < 64; i++){
        if(A[i] == 1){
            ans += (1ULL << i);
        }
    }

    cout << ans << endl;
}