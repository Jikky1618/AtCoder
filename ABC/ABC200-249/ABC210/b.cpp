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

    for(int i = 0; i < N; i++){
        if(S[i] == '1'){
            cout << (i % 2 == 0 ? "Takahashi" : "Aoki") << endl;
            return 0;
        }
    }
}