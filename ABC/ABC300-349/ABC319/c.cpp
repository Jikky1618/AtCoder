#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int FACT = 362880;
const vector<vector<int>> bingo = {
    {0, 1, 2},
    {3, 4, 5},
    {6, 7, 8},
    {0, 3, 6},
    {1, 4, 7},
    {2, 5, 8},
    {0, 4, 8},
    {2, 4, 6}
};
/*
    0 1 2
    3 4 5
    6 7 8
*/

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<vector<char>> c(3, vector<char>(3));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) cin >> c[i][j];
    }

    auto check = [&](const vector<int>& P) -> bool {
        vector<vector<int>> V(3, vector<int>(3, -1));
        for (int i = 0; i < 9; i++) {
            // マス (x, y) を知る
            int x = P[i] / 3, y = P[i] % 3;
            V[x][y] = c[x][y] - '0';
            // 各ビンゴとなるマスを調べる
            for (int j = 0; j < 8; j++) {
                bool known = true;  // ビンゴとなるマスが全て知られているか
                bool target = false;  // (x, y) を含むマスのビンゴか調べる
                for (int k = 0; k < 3; k++) {
                    int x2 = bingo[j][k] / 3, y2 = bingo[j][k] % 3;
                    if (x2 == x && y2 == y) target = true;
                    if (V[x2][y2] == -1) known = false;
                }
                if(!known || !target) continue;
                // (x, y) 以外の列のマス目の数が同じか
                vector<int> other;
                for (int k = 0; k < 3; k++) {
                    int x2 = bingo[j][k] / 3, y2 = bingo[j][k] % 3;
                    if (x2 != x || y2 != y) other.emplace_back(V[x2][y2]);
                }

                // (x, y) を含むマスのビンゴなら false
                if (other[0] == other[1]) {
                    return false;
                }
            }
        }
        return true;
    };

    vector<int> P(9);
    iota(P.begin(), P.end(), 0);
    int p = 0;
    do {
        if (check(P)) p++;
    } while (next_permutation(P.begin(), P.end()));

    double ans = double(p) / FACT;
    cout << ans << endl;
}