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
    int N, M;
    cin >> N >> M;
    vector<string> S(N);
    for(int i = 0; i < N; i++) cin >> S[i];

    vector<int> P(N);
    iota(P.begin(), P.end(), 0);
    debug(P);

    bool ans = false;
    do{
        bool flag = true;
        for(int i = 0; i < N - 1; i++){
            string T = S[P[i]], T2 = S[P[i + 1]];
            int diff = 0;
            for(int i = 0; i < M; i++) if(T[i] != T2[i]) diff++;
            if(diff != 1) flag = false;
        }

        if(flag) ans = true;
    }while(next_permutation(P.begin(), P.end()));

    cout << (ans ? "Yes" : "No") << endl;
}