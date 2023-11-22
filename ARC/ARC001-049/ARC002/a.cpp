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
    int Y;
    cin >> Y;
    if(Y % 400 == 0){
        cout << "YES" << endl;
    }else if(Y % 100 == 0){
        cout << "NO" << endl;
    }else if(Y % 4 == 0){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}