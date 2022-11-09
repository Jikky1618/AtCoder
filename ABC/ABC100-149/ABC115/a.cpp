#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int d;
    cin >> d;
    
    cout << "Christmas ";
    for(int i = 0; i < 25 - d; i++) cout << "Eve ";
    cout << endl;
    return 0;
}