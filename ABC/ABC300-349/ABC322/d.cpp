#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 4;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// H 行 W 列の V を反時計回りに 90 度回転させたものを返す
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
vector<vector<T>> trim(const vector<vector<T>>& V, char bg = '.') {
    int H = V.size(), W = V.front().size();
    int minH = H, minW = W, maxH = -1, maxW = -1;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            if (V[i][j] == bg) continue;
            minH = min(minH, i);
            maxH = max(maxH, i);
            minW = min(minW, j);
            maxW = max(maxW, j);
        }
    }

    // bg 以外の要素がなければ空の配列を返す
    if (minH == H) return vector<vector<T>>();
    vector res(maxH - minH + 1, vector<T>(maxW - minW + 1));
    for (int i = 0; i < maxH - minH + 1; i++) {
        for (int j = 0; j < maxW - minW + 1; j++)
            res[i][j] = V[i + minH][j + minW];
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector A(4, vector<char>(4)), B(4, vector<char>(4)), C(4, vector<char>(4));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cin >> A[i][j];
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cin >> B[i][j];
    }
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++) cin >> C[i][j];
    }

    A = trim(A); B = trim(B); C = trim(C);
    // A, B の位置を決めたとき, 4 x 4 に敷き詰められるか判定
    auto check = [&](int xa, int ya, int xb, int yb) -> bool {
        int HA = A.size(), WA = A.front().size();
        int HB = B.size(), WB = B.front().size();
        int HC = C.size(), WC = C.front().size();
        int xc = N, yc = N;
        vector G(2 * N, vector<char>(2 * N, '.'));
        for(int i = 0; i < HA; i++){
            for(int j = 0; j < WA; j++){
                if(G[i + xa][j + ya] == '#' && A[i][j] == '#') return false;
                if(A[i][j] == '#') G[i + xa][j + ya] = A[i][j];
            }
        }
        for(int i = 0; i < HB; i++){
            for(int j = 0; j < WB; j++){
                if(G[i + xb][j + yb] == '#' && B[i][j] == '#') return false;
                if(B[i][j] == '#') G[i + xb][j + yb] = B[i][j];
            }
        }
        for(int i = 0; i < HC; i++){
            for(int j = 0; j < WC; j++){
                if(G[i + xc][j + yc] == '#' && C[i][j] == '#') return false;
                if(C[i][j] == '#') G[i + xc][j + yc] = C[i][j];
            }
        }
        G = trim(G);
        int HG = G.size(), WG = G.front().size();
        if(HG != 4 || WG != 4) return false;
        for(int i = 0; i < HG; i++){
            for(int j = 0; j < WG; j++){
                if(G[i][j] != '#') return false;
            }
        }
        return true;
    };

    // 回転済みの A, B, C の位置を全探索
    auto search = [&]() -> bool {
        int HA = A.size(), WA = A.front().size();
        int HB = B.size(), WB = B.front().size();
        // A, B の位置を全探索
        for(int xa = 0; xa <= 2 * N - HA; xa++){
            for(int ya = 0; ya <= 2 * N - WA; ya++){
                for(int xb = 0; xb <= 2 * N - HB; xb++){
                    for(int yb = 0; yb <= 2 * N - WB; yb++){
                        if(check(xa, ya, xb, yb)) return true;
                    }
                }
            }
        }
        return false;
    };

    // 回転を全探索
    for(int ra = 0; ra < 4; ra++){
        for(int rb = 0; rb < 4; rb++){
            for(int rc = 0; rc < 4; rc++){
                if(search()){
                    cout << "Yes" << endl;
                    return 0;
                }
                C = rotate(C);
            }
            B = rotate(B);
        }
        A = rotate(A);
    }

    cout << "No" << endl;
}