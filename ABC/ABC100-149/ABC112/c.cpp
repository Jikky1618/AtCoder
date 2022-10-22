#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> x(n), y(n), h(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i] >> h[i];

    for(int cx = 0; cx <= 100; cx++){
        for(int cy = 0; cy <= 100; cy++){
            int H = 0;
            bool flag = true;
            for(int i = 0; i < n; i++){
                if(h[i] > 0) H = h[i] + abs(x[i] - cx) + abs(y[i] - cy);
            }
            for(int i = 0; i < n; i++){
                if(h[i] != max(H - abs(x[i] - cx) - abs(y[i] - cy), 0)) flag = false;
            }
            if(flag){
                cout << cx << " " << cy << " " << H << endl;
                return 0;
            }
        }
    }
    return 0;
}