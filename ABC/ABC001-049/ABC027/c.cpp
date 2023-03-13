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
    ll N;
    cin >> N;

    // ゲームのターン数を求める
    int turn = 0;
    for(ll i = N; i > 0; i /= 2) turn++;

    debug(turn);
    ll x = 1;
    // シミュレーション
    for(int i = 0; i < turn; i++){
        if(i % 2 == 0){
            if(turn % 2 == 0) x *= 2;
            else x = x * 2 + 1;
        }else{
            if(turn % 2 == 0) x = x * 2 + 1;
            else x *= 2;
        }

        if(x > N){
            if(i % 2 == 0){
                cout << "Aoki" << endl;
            }else{
                cout << "Takahashi" << endl;
            }
            return 0;
        }
    }
}