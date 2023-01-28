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
    string S, T;
    cin >> S >> T;
    int N = S.size(), M = T.size();

    auto match = [&](char S, char T) -> bool {
        return S == '?' || T == '?' || S == T;
    };

    vector<int> pre(M + 1), suf(M + 1);
    pre[0] = 1;
    for(int i = 0; i < M; i++){
        if(!match(S[i], T[i])) break;
        pre[i + 1] = 1;
    }
    suf[0] = 1;
    for(int i = 0; i < M; i++){
        if(!match(S[N - 1 - i], T[M - 1 - i])) break;
        suf[i + 1] = 1;
    }

    for(int i = 0; i < M + 1; i++){
        cout << (pre[i] && suf[M - i] ? "Yes" : "No") << endl;
    }
}