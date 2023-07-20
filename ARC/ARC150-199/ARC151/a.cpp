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
    int N;
    cin >> N;
    string S, T;
    cin >> S >> T;

    // S-T のハミング距離を求める
    int hamming = 0;
    for(int i = 0; i < N; i++){
        if(S[i] != T[i]) hamming++;
    }

    // 条件を満たす U は S-U, U-T で S-T の 1/2 倍
    // 奇数は存在しない
    if(hamming % 2 == 1){
        cout << -1 << endl;
        return 0;
    }

    string U = "";
    int cnt_S = 0, cnt_T = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == T[i]){
            U += '0';
        }else{
            // なるべく 0 を優先して取る
            if(cnt_S < hamming / 2 && S[i] == '0'){
                U += '0';
                cnt_S++;
            }else if(cnt_T < hamming / 2 && T[i] == '0'){
                U += '0';
                cnt_T++;
            }else if(cnt_S < hamming / 2 && S[i] == '1'){
                U += '1';
                cnt_S++;
            }else if(cnt_T < hamming / 2 && T[i] == '1'){
                U += '1';
                cnt_T++;
            }
        }
    }

    cout << U << endl;
}