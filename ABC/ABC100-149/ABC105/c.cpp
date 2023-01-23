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

    string ans = "";
    while(N != 0){
        int r = N % 2;
        if(r < 0) r += 2;
        N = (N - r) / (-2);
        ans += (char)('0' + r);
    }

    reverse(ans.begin(), ans.end());
    if(ans == "") ans = "0";
    cout << ans << endl;
}