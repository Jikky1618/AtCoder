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

    int ans = -1, val = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'o') val++;
        if(S[i] == '-' && val != 0){
            ans = max(ans, val);
            val = 0;
        }
    }

    val = 0;
    reverse(S.begin(), S.end());
    for(int i = 0; i < N; i++){
        if(S[i] == 'o') val++;
        if(S[i] == '-' && val != 0){
            ans = max(ans, val);
            val = 0;
        }
    }

    cout << ans << endl;
}