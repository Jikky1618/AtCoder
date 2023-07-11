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
    int A, B;
    cin >> A >> B;

    // 一応 [-200, 200] を調べる
    for(int X = -200; X <= 200; X++){
        for(int Y = -200; Y <= 200; Y++){
            if(X + Y == A && X - Y == B){
                cout << X << " " << Y << endl;
                return 0;
            }
        }
    }
}