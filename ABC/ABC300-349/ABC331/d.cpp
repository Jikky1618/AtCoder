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
    int N, Q;
    cin >> N >> Q;
    vector<string> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    // 累積和
    vector acc(N + 1, vector<int>(N + 1));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            acc[i + 1][j + 1] = acc[i][j + 1] + acc[i + 1][j] - acc[i][j] + (P[i][j] == 'B');
        }
    }

    // 区間[0, a][0, b] の中にある B の数
    auto sum = [&](int a, int b) -> ll {
        ll res = 0, ra = a / N, rb = b / N, ma = a % N, mb = b % N;
        res += acc[N][N] * ra * rb;
        res += acc[ma][N] * rb;
        res += acc[N][mb] * ra;
        res += acc[ma][mb];
        return res;
    };

    auto query = [&](int a, int b, int c, int d) -> ll {
        // 区間 [a, c][b, d] の中にある B の数
        // S[c][d] - S[a - 1][d] - S[c][b - 1] + S[a - 1][b - 1]
        return sum(c, d) - sum(a - 1, d) - sum(c, b - 1) + sum(a - 1, b - 1);
    };

    while(Q--){
        int a, b, c, d;
        cin >> a >> b >> c >> d, a++, b++, c++, d++;
        cout << query(a, b, c, d) << '\n';
    }
}