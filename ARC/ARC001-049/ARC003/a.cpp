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
    string S;
    cin >> S;

    int sum = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'A') sum += 4;
        if(S[i] == 'B') sum += 3;
        if(S[i] == 'C') sum += 2;
        if(S[i] == 'D') sum += 1;
    }

    cout << (double)sum / N << endl;
}