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
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;

    int cnt = 1;
    string ans = "";
    for(int i = 0; i < N; i++){
        if(S[i] == 'o' && cnt <= K) ans += "o", cnt++;
        else ans += "x";
    }

    cout << ans << endl;
}