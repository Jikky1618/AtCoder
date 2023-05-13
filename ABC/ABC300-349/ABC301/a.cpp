#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

template<class T, class U>
T ceil(T x, U y){
    return (x ? (x + y - 1) / y : x / y);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;

    int A = 0, T = 0;
    for(int i = 0; i < N; i++){
        if(S[i] == 'A') A++;
        if(S[i] == 'T') T++;

        if(A == ceil(N, 2)){
            cout << "A" << endl;
            return 0;
        }
        if(T == ceil(N, 2)){
            cout <<  "T" << endl;
            return 0;
        }
    }
}