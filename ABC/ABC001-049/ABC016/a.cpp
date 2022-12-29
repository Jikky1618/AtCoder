#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int M, D;
    cin >> M >> D;
    cout << (M % D == 0 ? "YES" : "NO") << endl;
    return 0;
}