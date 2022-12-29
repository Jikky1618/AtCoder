#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    for(int i = 0; i < H; i++) cin >> a[i];

    for(int i = 0; i < H + 2; i++){
        if(i == 0 || i == H + 1){
            for(int j = 0; j < W + 2; j++) cout << '#';
            cout << endl;
        }else{
            cout << '#' << a[i - 1] << '#' << endl;
        }
    }
    return 0;
}