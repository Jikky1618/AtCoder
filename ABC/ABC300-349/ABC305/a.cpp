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

    int dist = 1000, ans = 0;
    for(int i = N - 5; i <= N + 5; i++){
        if(i < 0 || i > 100) continue;
        if(i % 5 == 0 && abs(i - N) < dist){
            dist = abs(i - N);
            ans = i;
        }
    }

    cout << ans << endl;
}