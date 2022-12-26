#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll A, B, C, K;
    cin >> A >> B >> C >> K;

    if(K % 2 == 0){
        cout << A - B << endl;
    }else{
        cout << B - A << endl;
    }
    return 0;
}