#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, H, W;
    cin >> N >> H >> W;
    cout << (N - H + 1) * (N - W + 1) << endl;
    return 0;
}