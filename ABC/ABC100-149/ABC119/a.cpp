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
    string S;
    cin >> S;
    
    int Y = stoi(S.substr(0, 4));
    int M = stoi(S.substr(5, 2));
    if((Y == 2019 && M <= 4) || Y < 2019){
        cout << "Heisei" << endl;
    }else{
        cout << "TBD" << endl;
    }
}