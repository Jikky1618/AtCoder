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
    string S;
    cin >> N >> S;

    int Red = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'R') Red++;
    }

    // L := i番目よりも左側の白の数, R := i番目よりも右側の赤の数
    int L = 0, R = Red, ans = max(L, R);
    for(int i = 0; i < N; i++){
        if(S[i] == 'W') L++;
        if(S[i] == 'R') R--;
        ans = min(ans, max(L, R));
    }

    cout << ans << endl;
}