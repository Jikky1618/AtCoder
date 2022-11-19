#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n;
    cin >> n;
    if(n / 10 == n % 10){
        cout << 1 << endl;
    }else{
        cout << 0 << endl;
    }
    
    return 0;
}