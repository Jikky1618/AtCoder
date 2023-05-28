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
    string S;
    cin >> S;

    int N = S.size();
    ll ans = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'U'){
            ans += i * 2;
            ans += (N - i - 1);
        }else{
            ans += i;
            ans += (N - i - 1) * 2;
        }
    }

    cout << ans << endl;
}