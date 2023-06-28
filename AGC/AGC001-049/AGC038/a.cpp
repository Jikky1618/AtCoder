#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// O(2^{HW}HW)
bool naive(ll H, ll W, ll A, ll B){
    for(ll bit = 0; bit < (1LL << (H * W)); bit++){
        vector<string> S(H);
        for(int i = 0; i < H; i++){
            string T;
            for(int j = 0; j < W; j++){
                if((bit >> (i * W + j)) & 1){
                    T += '1';
                }else{
                    T += '0';
                }
            }
            S[i] = T;
        }
        // 条件check
        bool flag = true;
        for(int i = 0; i < H; i++){
            ll cnt = 0;
            for(int j = 0; j < W; j++){
                cnt += (S[i][j] == '1');
            }
            if(min(cnt, W - cnt) != A) flag = false;
        }
        for(int i = 0; i < W; i++){
            ll cnt = 0;
            for(int j = 0; j < H; j++){
                cnt += (S[j][i] == '1');
            }
            if(min(cnt, H - cnt) != B) flag = false;
        }

        if(flag){
            debug(S);
            return true;
        }
    }
    return false;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W, A, B;
    cin >> H >> W >> A >> B;

    
    // naive(H, W, A, B);
    // 1の数がA, 0の数が H - Aの列と, 0の数がA, 1の数がH - Aの列で構成できる
    string M1 = string(A, '1') + string(W - A, '0');
    string M2 = string(A, '0') + string(W - A, '1');
    for(int i = 0; i < B; i++){
        cout << M1 << endl;
    }
    for(int i = 0; i < H - B; i++){
        cout << M2 << endl;
    }
}