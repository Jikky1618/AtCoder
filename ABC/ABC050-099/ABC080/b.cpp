#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int N){
    string S = to_string(N);
    int res = 0;
    for(auto c: S) res += c - '0';
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    cout << (N % f(N) == 0 ? "Yes" : "No") << endl;
    return 0;
}