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
    string S;
    cin >> N >> S;

    bool flag1 = false, flag2 = true;
    for(auto c: S){
        if(c == 'o') flag1 = true;
        if(c == 'x') flag2 = false;
    }

    cout << (flag1 && flag2 ? "Yes" : "No") << endl;
}