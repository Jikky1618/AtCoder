#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;
    int N = S.size();

    // 隣接している文字で等しいのがあるかどうか
    for(int i = 0; i < N - 1; i++) {
        if(S[i] == S[i + 1]) {
            cout << i + 1 << " " << i + 2 << '\n';
            return 0;
        }
    }

    // 隣接 3 文字も見る
    for(int i = 0; i < N - 2; i++) {
        string sub = S.substr(i, 3);
        if(sub[0] == sub[2]) {
            cout << i + 1 << " " << i + 3 << '\n';
            return 0;
        }
    }

    cout << -1 << " " << -1 << '\n';
}