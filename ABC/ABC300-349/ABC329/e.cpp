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

    queue<int> que;
    vector<int> seen(N);

    auto check = [&](int pos) -> bool {
        bool flag = false; // # 以外の文字があるか
        for(int i = 0; i < M; i++){
            if(S[pos + i] == T[i]) flag = true;
            if(S[pos + i] != T[i] && S[pos + i] != '#') return false;
        }
        return flag;
    };

    for(int i = 0; i + M <= N; i++){
        if(check(i)) que.emplace(i), seen[i] = true;
    }

    while(!que.empty()){
        int pos = que.front();
        que.pop();
        for(int i = 0; i < M; i++){
            S[pos + i] = '#';
        }
        for(int i = pos - M + 1; i <= pos + M - 1; i++){
            if(i < 0 || i + M > N) continue;
            if(seen[i]) continue;
            if(check(i)) que.emplace(i), seen[i] = true;
        }
    }

    debug(S);
    cout << (S == string(N, '#') ? "Yes" : "No") << endl;
}