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
    string S, T;
    cin >> S >> T;

    // S の連続部分列で T を構築できる pos を que に入れる
    auto check = [&](int pos) -> bool {
        bool flag = true, other = false;
        for(int i = 0; i < M; i++){
            if(S[pos + i] != '#') other = true;
            if(S[pos + i] != T[i] && S[pos + i] != '#') flag = false;
        }
        return flag && other;
    };

    queue<int> que;
    for(int i = 0; i < N - M + 1; i++) if(check(i)) que.emplace(i);

    while(!que.empty()){
        int p = que.front(); que.pop();
        for(int i = 0; i < M; i++) S[p + i] = '#';
        // 前後 m 要素を見て, # + S の連続部分列で T を構築できる pos を que に入れる
        for(int i = max(0, p - M + 1); i < min(N - M + 1, p + M + 1); i++){
            if(check(i)) que.emplace(i);
        }
    }

    cout << (S == string(N, '#') ? "Yes" : "No") << endl;
}