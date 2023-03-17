#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

const int MAX = 1e6 + 1;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> A(N);
    for(int i = 0; i < N; i++) cin >> A[i];

    // setwise coprimeではないかを判定
    int g = 0;
    for(int i = 0; i < N; i++) g = gcd(g, A[i]);

    if(g != 1){
        cout << "not coprime" << endl;
        return 0;
    }

    // pairwise coprimeかどうかを判定
    vector<int> num(MAX);
    for(int i = 0; i < N; i++) num[A[i]]++;

    bool flag = true;
    // 各iについて(iは素数だけ調べれば十分)
    for(int i = 2; i < MAX; i++){
        int sum = 0;
        // iを素因数に持つAの要素数が高々1以下ならpairwise coprime
        for(int j = i; j < MAX; j += i) sum += num[j];
        if(sum > 1) flag = false;
    }

    cout << (flag ? "pairwise coprime" : "setwise coprime") << endl;
}