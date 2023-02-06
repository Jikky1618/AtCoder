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
    vector A(H, vector<int>(W)), B(H, vector<int>(W));
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> A[i][j];
        }
    }

    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            cin >> B[i][j];
        }
    }

    auto operation = [&](int h, int w, int val) -> void {
        for(int i = h; i <= h + 1; i++){
            for(int j = w; j <= w + 1; j++){
                A[i][j] += val;
            }
        }
    };

    ll ans = 0;
    for(int i = 0; i < H - 1; i++){
        for(int j = 0; j < W - 1; j++){
            ll diff = B[i][j] - A[i][j];
            operation(i, j, diff);
            ans += abs(diff);
        }
    }

    bool flag = true;
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(A[i][j] != B[i][j]) flag = false;
        }
    }

    if(flag){
        cout << "Yes" << endl << ans << endl;
    }else{
        cout << "No" << endl;
    }
}