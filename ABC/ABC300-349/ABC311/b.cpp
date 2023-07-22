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
    int N, D;
    cin >>  N >> D;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    int ans = 0, cnt = 0;
    for(int i = 0; i < D; i++){
        bool ok = true;
        for(int j = 0; j < N; j++){
            if(S[j][i] == 'x') ok = false;
        }
        if(ok){
            cnt++;
        }else{
            cnt = 0;
        }
        ans = max(ans, cnt);
    }

    cout << ans << endl;
}