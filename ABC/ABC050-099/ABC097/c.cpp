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
    int K;
    cin >> S >> K;

    vector<string> V;
    for(int i = 0; i < S.size(); i++){
        // K番目に小さいsubstringは高々K文字
        for(int j = 1; j <= K; j++){
            V.push_back(S.substr(i, j));
        }
    }

    sort(V.begin(), V.end());
    V.erase(unique(V.begin(), V.end()), V.end());

    cout << V[K - 1] << endl;
}