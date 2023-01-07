#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int T;
    cin >> T;

    while(T--){
        ll N;
        cin >> N;
        
        ll p = 0, q = 0;
        for(ll i = 2; i * i * i <= N; i++){
            if(N % i != 0) continue;

            if((N / i) % i == 0){
                p = i; q = N / i / i;
            }else{
                p = (ll)sqrt(N / i); q = i;
            }
            break;
        }
        cout << p << " " << q << "\n";
    }
}