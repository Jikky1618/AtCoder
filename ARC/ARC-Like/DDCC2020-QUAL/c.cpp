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
    int H, W, K;
    cin >> H >> W >> K;
    vector<string> S(H);
    for(int i = 0; i < H; i++) cin >> S[i];

    vector A(H, vector<int>(W, -1)); // 答え用


    // 行単位でかんがえる
    int id = 1;
    for(int i = 0; i < H; i++){
        int cnt = count(S[i].begin(), S[i].end(), '#');
        // 行にいちごがあれば
        if(cnt != 0){
            int val = 0;
            // 左から右順にまだ未決定なら id を採用していく
            for(int j = 0; j < W; j++){
                if(S[i][j] == '#') val++;
                A[i][j] = (val ? val - 1 : 0) + id;
            }
            // 右から左に同じことをする
            for(int j = W - 1; j > 0; j--){
                if(A[i][j - 1] == -1){
                    A[i][j - 1] = A[i][j];
                }
            }

            id += val;
        }
    }
    debug(A);

    // 上から下順にまだ未決定の行があれば, 1つ上の行と同じにする
    for(int i = 0; i < H - 1; i++){
        if(A[i + 1].front() == -1){
            A[i + 1] = A[i];
        }
    }

    // 下から上順にまだ未決定の行があれば, 1つ下の行と同じにする
    for(int i = H - 1; i > 0; i--){
        if(A[i - 1].front() == -1){
            A[i - 1] = A[i];
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << A[i][j] << " \n"[j == W - 1];
        }
    }
}