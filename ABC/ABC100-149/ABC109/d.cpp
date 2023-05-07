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
    int H, W;
    cin >> H >> W;
    vector A(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++) cin >> A[i][j];
    }

    vector<tuple<int, int, int, int>> ans;
    // 奇数マスを全て右に詰める(これで少なくとも右端以外偶数マス)
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W - 1; j++){
            if(A[i][j] % 2 == 1){
                A[i][j]--, A[i][j + 1]++;
                ans.emplace_back(i, j, i, j + 1);
            }
        }
    }

    // 一番右の奇数マスを全て下に詰める(これで少なくとも右下以外偶数マス)
    for(int i = 0; i < H - 1; i++){
        if(A[i][W - 1] % 2 == 1){
            A[i][W - 1]--, A[i + 1][W - 1]++;
            ans.emplace_back(i, W - 1, i + 1, W - 1);
        }
    }

    int N = ans.size();
    cout << N << "\n";
    for(int i = 0; i < N; i++){
        auto [X, Y, x, y] = ans[i];
        cout << X + 1 << " " << Y + 1 << " " << x + 1 << " " << y + 1 << "\n";
    }
}