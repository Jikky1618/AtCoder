#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll X, A, D, N;
    cin >> X >> A >> D >> N;

    // 等差数列の反転
    if(D < 0){
        A = A + D * (N - 1);
        D *= -1;
    }
    // L: 末項
    ll L = A + D * (N - 1);
    if(X <= A){
        cout << A - X << endl;
    }else if(L <= X){
        cout << X - L << endl;
    }else{
        cout << min((X - A) % D, D - (X - A) % D) << endl;
    }

    return 0;
}