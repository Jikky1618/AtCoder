#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// H 行 W 列の V を 90 度回転させたものを返す
template <class T>
vector<vector<T>> rotate(const vector<vector<T>>& V) {
    int H = V.size(), W = V.front().size();
    vector res(W, vector<T>(H));
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            res[W - 1 - j][i] = V[i][j];
        }
    }
    return res;
}

// H 行 W 列の V を bg 以外を全て含む最小矩形でトリミングしたものを返す
template <class T>
vector<vector<T>> trim(const vector<vector<T>>& V, char bg = '.'){
    int H = V.size(), W = V.front().size();
    int minH = H, minW = W, maxH = -1, maxW = -1;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(V[i][j] == bg) continue;
            minH = min(minH, i);
            maxH = max(maxH, i);
            minW = min(minW, j);
            maxW = max(maxW, j);
        }
    }

    // bg 以外の要素がなければ空の配列を返す
    if(minH == H) return vector<vector<T>>();
    vector res(maxH - minH + 1, vector<T>(maxW - minW + 1));
    for(int i = 0; i < maxH - minH + 1; i++){
        for(int j = 0; j < maxW - minW + 1; j++) res[i][j] = V[i + minH][j + minW];
    }
    return res;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector S(N, vector<char>(N)), T(N, vector<char>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> S[i][j];
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) cin >> T[i][j];
    }

    S = trim(S), T = trim(T);
    bool same = false;
    for(int i = 0; i < 4; i++){
        S = rotate(S);
        if(S == T) same = true;
    }

    cout << (same ? "Yes" : "No") << endl;
}