#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

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
    int HA, WA;
    cin >> HA >> WA;
    vector A(HA, vector<char>(WA));
    for(int i = 0; i < HA; i++){
        for(int j = 0; j < WA; j++) cin >> A[i][j];
    }
    int HB, WB;
    cin >> HB >> WB;
    vector B(HB, vector<char>(WB));
    for(int i = 0; i < HB; i++){
        for(int j = 0; j < WB; j++) cin >> B[i][j];
    }
    int HX, WX;
    cin >> HX >> WX;
    vector X(HX, vector<char>(WX));
    for(int i = 0; i < HX; i++){
        for(int j = 0; j < WX; j++) cin >> X[i][j];
    }

    // A, B, X をトリミング
    A = trim(A), B = trim(B), X = trim(X);
    HA = A.size(), WA = A.front().size();
    HB = B.size(), WB = B.front().size();
    HX = X.size(), WX = X.front().size();

    // B の開始位置を全探索
    // A の開始位置は (10, 10) に固定
    for(int xb = 0; xb < 30 - HB; xb++){
        for(int yb = 0; yb < 30 - WB; yb++){
            // A と B を重ねた C を作成
            vector C(30, vector<char>(30, '.'));
            for(int i = 0; i < HA; i++){
                for(int j = 0; j < WA; j++){
                    if(A[i][j] == '#') C[i + 10][j + 10] = '#';
                }
            }
            for(int i = 0; i < HB; i++){
                for(int j = 0; j < WB; j++){
                    if(B[i][j] == '#') C[i + xb][j + yb] = '#';
                }
            }
            // C をトリミング
            C = trim(C);
            if(C == X){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl; 
}