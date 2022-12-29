#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int W, H;
    cin >> W >> H;
    cout << (W == H * 4 / 3 ? "4:3" : "16:9") << endl;
    return 0;
}