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
    ll R, G, B, N;
    cin >> R >> G >> B >> N;

    ll ans = 0;
    for(int r = 0; r <= N; r++){
        if(r * R > N) break;
        for(int g = 0; g <= N; g++){
            if(r * R + g * G > N) break;
            int b = N - (r * R + g * G);
            if(b % B == 0){
                ans++;
            }
        }
    }

    cout << ans << endl;
}