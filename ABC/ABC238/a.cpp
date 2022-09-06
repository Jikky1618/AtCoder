#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    if(pow(2,n) > n * n) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}