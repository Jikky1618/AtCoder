#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int y;
    cin >> y;

    int ans;
    if(y % 4 == 0) ans = y + 2;
    if(y % 4 == 1) ans = y + 1;
    if(y % 4 == 2) ans = y;
    if(y % 4 == 3) ans = y + 3;

    cout << ans << endl;

    return 0;
}
