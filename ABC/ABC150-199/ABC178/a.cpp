#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x;
    cin >> x;
    if(x == 0) x = 1;
    else if(x == 1) x = 0;

    cout << x << endl;

    return 0;
}