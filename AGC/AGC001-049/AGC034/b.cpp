#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 1 TLE
ll naive(string S){
    ll res = 0;
    int N = S.size();
    for(int i = 0; i < N - 2; i++){
        if(S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C'){
            S[i] = 'B', S[i + 1] = 'C', S[i + 2] = 'A';
            res++;
            if(0 <= i - 1) i -= 2;
            debug(S, res, i);
        }
    }
    return res;
}

ll solve(string S){
    // BC を X に置き換える
    int N = S.size();
    string T;
    for(int i = 0; i < N; i++){
        if(i + 1 < N && S[i] == 'B' && S[i + 1] == 'C'){
            T += 'X', i++;
        }else{
            T += S[i];
        }
    }
    debug(T);

    ll ans = 0, cnt = 0;
    for(unsigned i = 0; i < T.size(); i++){
        if(T[i] == 'A'){
            cnt++;
        }else if(T[i] == 'X'){
            ans += cnt;
        }else{
            cnt = 0;
        }
    }

    return ans;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    // cout << naive(S) << '\n';
    cout << solve(S) << endl;
}