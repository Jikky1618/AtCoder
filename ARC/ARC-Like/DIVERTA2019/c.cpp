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
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int ans = 0;
    for(int i = 0; i < N; i++){
        int M = S[i].size();
        for(int j = 0; j < M - 1; j++){
            if(S[i][j] == 'A' && S[i][j + 1] == 'B') ans++;
        }
    }
    debug(ans);
    // x := B...A の個数
    // y := ...A の個数
    // z := B... の個数
    int x = 0, y = 0, z = 0;
    for(int i = 0; i < N; i++){
        if(S[i].front() == 'B' && S[i].back() == 'A') x++;
        else if(S[i].back() == 'A') y++;
        else if(S[i].front() == 'B') z++;
    }
    debug(x, y, z);

    if(x == 0){
        ans += min(y, z);
    }else{
        if(y == 0 && z == 0){
            ans += x - 1;
        }else if(y == 0 || z == 0){
            ans += x;
        }else if(y == z){
            ans += min(y, z) - 1;
            ans += x + 1;
        }else{
            ans += min(y, z);
            ans += x;
        }
    }

    cout << ans << endl;
}