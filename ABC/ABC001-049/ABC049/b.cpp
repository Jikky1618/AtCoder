#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> C(H);
    for(int i = 0; i < H; i++) cin >> C[i];

    for(int i = 0; i < 2 * H; i++){
        cout << C[i / 2] << endl;
    }
    return 0;
}