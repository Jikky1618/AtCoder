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
    int N, M;
    cin >> N >> M;

    bool flag = true;
    // N が奇数の場合
    if(N % 2 == 1){
        int a = 1, b = N;
        for(int i = 0; i < M; i++){
            cout << a << " " << b << '\n';
            a++, b--;
        }
    // 偶数の場合
    }else{
        int a = 1, b = N;
        for(int i = 0; i < M; i++){
            cout << a << " " << b << '\n';
            a++, b--;
            // 両側からの距離の関係が逆転した場合、ずらす
            if(flag && b - a <= (a - 1) + (N - b) + 1) a++, flag = false;
        }
    }
}