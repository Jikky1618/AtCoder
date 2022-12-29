#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a, b;
    cin >> a >> b;
    
    int diff = b - a, h = 0;
    for(int i = 0; i <= diff; i++) h += i;

    cout << h - b << endl;
    return 0;
}