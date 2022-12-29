#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, x;
    cin >> n >> x;
    cout << min(x - 1, n - x) << endl;
    return 0;
}