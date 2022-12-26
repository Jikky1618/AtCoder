#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int D, N;
    cin >> D >> N;

    if(D == 0){
        if(N == 100) cout << N + 1 << endl;
        else cout << N << endl;
    }
    if(D == 1){
        if(N == 100) cout << 100 * (N + 1) << endl;
        else cout << 100 * N << endl;
    }
    if(D == 2){
        if(N == 100) cout << 10000 * (N + 1) << endl;
        else cout << 10000 * N  << endl;
    }
    return 0;
}