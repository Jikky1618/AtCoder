#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c;
    cin >> a >> b >> c;
    cout << max(c - (a - b),0) << endl;
    return 0;
}