#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H1, W1, H2, W2;
    cin >> H1 >> W1 >> H2 >> W2;
    cout << (H1 == H2 || H1 == W2 || H2 == W1 || W1 == W2 ? "YES": "NO") << endl;
    return 0;
}