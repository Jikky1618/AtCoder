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

    vector<bool> h(H), w(W);
    for(int i = 0; i < H; i++){
        for(int j = 0; j < W; j++){
            if(a[i][j] == '#') h[i] = true, w[j] = true;
        }
    }

    for(int i = 0; i < H; i++){
        if(h[i]){
            for(int j = 0; j < W; j++){
                if(w[j]){
                    cout << a[i][j];
                }
            }
            cout << endl;
        }
    }
    
    return 0;
}