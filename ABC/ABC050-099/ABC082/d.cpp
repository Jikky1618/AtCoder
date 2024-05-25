#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<pair<char, int>> run_length_encodeing(const string& S) {
    vector<pair<char, int>> res;
    for (auto c : S) {
        if (!res.empty() && c == res.back().first) {
            res.back().second++;
        } else {
            res.emplace_back(c, 1);
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    int gx, gy;
    cin >> S >> gx >> gy;
    auto rle = run_length_encodeing(S);
    debug(rle);
    // x, y 方向の移動
    vector<int> X, Y;
    int dir = 0;
    for(auto [c, cnt]: rle) {
        if(c == 'F') {
            if(dir & 1) {
                Y.emplace_back(cnt);
            } else {
                X.emplace_back(cnt);
            }
        } else {
            // T が奇数回なら方向転換
            dir ^= (cnt & 1);
        }
    }

    debug(X, Y);
    // dpx[x] := x に移動できるか, dpy[y] := y に移動できるかを持つ
    map<int, bool> dpx, dpy;
    dpx[0] = dpy[0] = true;
    int N = X.size(), M = Y.size();
    for(int i = 0; i < N; i++) {
        map<int, bool> next;
        for(auto [k, v]: dpx) {
            next[k + X[i]] = true;
            // 注意: 初手 T がある場合のみ, 初手で -X[i] に移動できる
            if(i > 0 || (i == 0 && S.front() == 'T')) next[k - X[i]] = true;
        }
        swap(dpx, next);
    }
    for(int i = 0; i < M; i++) {
        map<int, bool> next;
        for(auto [k, v]: dpy) {
            next[k + Y[i]] = true;
            next[k - Y[i]] = true;
        }
        swap(dpy, next);
    }

    cout << ((dpx[gx] && dpy[gy]) ? "Yes" : "No") << '\n';
}