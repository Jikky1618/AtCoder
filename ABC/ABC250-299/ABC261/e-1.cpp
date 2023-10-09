#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// num を r 進数表記したときの桁の配列を返す
vector<int> digits_convert(ll num, int r = 10) {
    vector<int> res;
    // corner case: num = 0
    if (num == 0) {
        res.emplace_back(0);
        return res;
    }
    // mod |r| を取れば最下位桁順に決定していく
    while (num != 0) {
        int d = (num % abs(r) + abs(r)) % abs(r);
        res.emplace_back(d);
        num = (num - d) / r;
    }
    reverse(res.begin(), res.end());
    return res;
}

// r 進表記で上位桁から順に digits が並んだ数の値を返す．
ll integer_convert(vector<int>& digits, int r = 10) {
    int N = int(digits.size());

    ll res = 0, base = 1;
    for (int i = N - 1; i >= 0; i--) {
        res += digits[i] * base;
        base *= r;
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, C;
    cin >> N >> C;
    vector<int> T(N), A(N);
    for(int i = 0; i < N; i++) cin >> T[i] >> A[i];

    const int MAX = 30;
    // acc[i] := 00...00(2) を i 回目の操作をしたときの bit
    // acc2[i] := 11...11(2) を i 回目の操作をしたときの bit
    vector<vector<int>> acc(N + 1, vector<int>(MAX));
    vector<vector<int>> acc2(N + 1, vector<int>(MAX, 1));
    for(int i = 0; i < N; i++){
        auto d = digits_convert(A[i], 2);
        // d の先頭に 0 を追加
        while(d.size() < MAX) d.insert(d.begin(), 0);
        
        for(int j = 0; j < MAX; j++){
            if(T[i] == 1){
                acc[i + 1][j] = acc[i][j] & d[j];
                acc2[i + 1][j] = acc2[i][j] & d[j];
            }
            if(T[i] == 2){
                acc[i + 1][j] = acc[i][j] | d[j];
                acc2[i + 1][j] = acc2[i][j] | d[j];
            }
            if(T[i] == 3){
                acc[i + 1][j] = acc[i][j] ^ d[j];
                acc2[i + 1][j] = acc2[i][j] ^ d[j];
            }
        }
    }

    int X = C;
    for(int i = 1; i <= N; i++){
        auto d = digits_convert(X, 2);
        // d の先頭に 0 を追加
        while(d.size() < MAX) d.insert(d.begin(), 0);
        vector<int> res(MAX);
        for(int j = 0; j < MAX; j++){
            res[j] = (d[j] == 0 ? acc[i][j] : acc2[i][j]);
        }
        auto ans = integer_convert(res, 2);
        cout << ans << '\n';
        X = ans;
    }
}