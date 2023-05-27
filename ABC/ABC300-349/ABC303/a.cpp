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
    
    bool flag = true;
    for(int i = 0; i < N; i++){
        if(S[i] == T[i]) continue;
        if((S[i] == '1' && T[i] == 'l') ||(S[i] == 'l' && T[i] == '1')) continue;
        if((S[i] == '0' && T[i] == 'o') ||(S[i] == 'o' && T[i] == '0')) continue;
        flag = false;
    }

    cout << (flag ? "Yes" : "No") << endl;
}