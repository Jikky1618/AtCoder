#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x,y,z;
    cin >> x >> y >> z;

    swap(x,y);
    swap(x,z);

    cout << x << " " << y << " " << z << endl;
    
    return 0;
}