#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;

    for(ll h = 1; h <= 3500; h++){
        for(ll n = 1; n <= 3500; n++){
            // 4*h*n*w == N*(n*w+h*w+h*n)
            ll t = h*n*N, b = 4*h*n-n*N-h*N;
            if(b != 0 && t % b == 0 && t / b > 0){
                ll w = t / b;
                cout << h << " " << n << " " << w << endl;
                return 0;
            }
        }
    }
    return 0;
}