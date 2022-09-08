#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int l1,r1,l2,r2;
    cin >> l1 >> r1 >> l2 >> r2;
    int ans = max(0,min(r1,r2)-max(l1,l2));

    cout << ans << endl;

    return 0;
}