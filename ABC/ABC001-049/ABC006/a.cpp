#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    string S = to_string(N);
    cout << (N % 3 == 0 || count(S.begin(), S.end(), '3') ? "YES" : "NO") << endl;
    return 0;
}