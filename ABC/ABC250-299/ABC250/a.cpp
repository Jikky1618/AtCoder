#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int h,w,r,c;
    cin >> h >> w >> r >> c;
    int res = 4;
    if(h == 1) res--;
    if(w == 1) res--;
    if(r == 1 || r == h) res--;
    if(c == 1 || c == w) res--;

    cout << res << endl;

    return 0;
}