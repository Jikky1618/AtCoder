#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = (1 << 30) - 1;

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

    int N = S.size(), ans = INF;
    for(char c = 'a'; c <= 'z'; c++){
        int cnt = 0, len = 0;
        for(int i = 0; i < N; i++){
            if(S[i] != c) len++;
            else len = 0;
            cnt = max(cnt, len);
        }
        ans = min(ans, cnt);
    }

    cout << ans << endl;
}