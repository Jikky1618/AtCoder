#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int S(int N){
    string s = to_string(N);
    int res = 0;
    for(auto c: s){
        res += c - '0';
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    cout << (N % S(N) == 0 ? "Yes" : "No") << endl;
    return 0;
}