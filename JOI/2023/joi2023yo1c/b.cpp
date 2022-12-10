#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int A, B;
    cin >> A >> B;
    if(A + B * 7 <= 30){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    return 0;
}