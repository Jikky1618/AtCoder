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
    int H, W, N;
    cin >> H >> W >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    vector<int> C;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < A[i]; j++){
            C.emplace_back(i + 1);
        }
    }

    vector ans(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            ans[i][j] = C[i * W + j];
        }
    }
    for(int i = 0; i < H; i++){
        if(i % 2 == 0){
            reverse(ans[i].begin(), ans[i].end());
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cout << ans[i][j] << " \n"[j == W - 1];
        }
    }
}