#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    
    if(n % 10 == 3) cout << "bon" << endl;
    else if(n % 10 == 0 || n % 10 == 1 || n % 10 == 6 || n % 10 == 8) cout << "pon" << endl;
    else cout << "hon" << endl;

    return 0;
}