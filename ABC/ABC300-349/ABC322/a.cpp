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
    for(int i = 0; i < N - 2; i++){
        if(S[i] == 'A' && S[i + 1] == 'B' && S[i + 2] == 'C'){
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;
}