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

    bool flag = true;
    for(unsigned i = 0; i < S.size(); i += 2){
        if(S[i] == 'h' && S[i + 1] == 'i') continue;
        flag = false;
    }

    cout << (flag ? "Yes" : "No") << endl;
}