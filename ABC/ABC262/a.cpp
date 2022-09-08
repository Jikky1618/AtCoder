#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int y;
    cin >> y;

    int ans;
    if(y % 4 == 0) ans = y + 2;
    else if(y % 4 == 2) ans = y;
    else ans = y + (y % 4);

    cout << ans << endl;

    return 0;
}
