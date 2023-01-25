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
    ll N, M;
    cin >> N >> M;

    ll ans;
    if(N == 1 && M == 1){
        ans = 1;
    }else if(N == 1 || M == 1){
        ans = N * M - 2;
    }else{
        ans = (N - 2) * (M - 2);
    }

    cout << ans << endl;
}