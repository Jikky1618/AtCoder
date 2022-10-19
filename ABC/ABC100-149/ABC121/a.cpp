#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int H,W,h,w;
    cin >> H >> W >> h >> w;
    cout << H * W - h * W - w * H + w * h << endl;

    return 0;
}