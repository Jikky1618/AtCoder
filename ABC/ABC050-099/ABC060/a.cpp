#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string A, B, C;
    cin >> A >> B >> C;
    cout << (A.back() == B.front() && B.back() == C.front() ? "YES" : "NO") << endl;
    return 0;
}