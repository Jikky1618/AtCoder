#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x,t;
    cin >> n >> x >> t;
    cout << (n + x - 1) / x * t << endl;
    
    return 0;
}