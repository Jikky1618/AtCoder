#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    cout << max(min(b,d) - max(a,c),0) << endl;
    return 0;
}