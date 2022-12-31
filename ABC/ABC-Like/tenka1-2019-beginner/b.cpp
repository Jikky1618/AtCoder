#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    string S;
    cin >> N >> S >> K;

    char c = S[K - 1];
    for(auto &&s: S) if(s != c) s = '*';

    cout << S << endl;
    return 0;
}