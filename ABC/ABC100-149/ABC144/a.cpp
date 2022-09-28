#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    
    if(1 <= a && a <= 9 && 1 <= b && b <= 9){
        cout << a * b << endl;
    }else{
        cout << -1 << endl;
    }
    return 0;
}