#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll n,x,y;
    cin >> n >> x >> y;

    vector<ll> red(n+1);
    vector<ll> blue(n+1);
    red[n] = 1;
    while(1){
        bool flag = true;
        for(int i = n; i >= 2; i--){
        while(red[i] > 0){
            red[i]--;
            red[i-1]++;
            blue[i] += x;
            }
        }
        for(int i = n; i >= 2; i--){
            while(blue[i] > 0){
                blue[i]--;
                red[i-1]++;
                blue[i-1] += y;
            }
        }
        for(int i = 2; i <= n; i++){
            if(red[i] > 0) flag = false;
            if(blue[i] > 0) flag = false;
        }
        if(flag) break;
    }

    cout << blue[1] << endl;
    return 0;
}