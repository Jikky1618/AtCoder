#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int x,y,z;
    cin >> x >> y >> z;

    bool useHammer = false;
    bool can = true;
    // Start...y...x or x...y...Start
    if((0 < y && y < x) || (x < y && y < 0)) useHammer = true;
    // Start...y...z or z...y...Start
    if((useHammer && 0 < y && y < z) || (useHammer && z < y && y < 0)) can = false;

    int ans = 0;
    // use hammer or don't use hammer
    if(useHammer) ans = abs(z) +abs(x - z);
    else ans = abs(x);
    // cannot goal
    if(!can) ans = -1;

    cout << ans << endl;
    return 0;
}