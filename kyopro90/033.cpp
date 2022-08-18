#include <bits/stdc++.h>
using namespace std;

int main(){
    int h,w;
    cin >> h >> w;
    // Corner case
    if(h == 1 || w == 1) cout << h * w << endl;
    // Output
    else cout << ((h + 1) / 2) * ((w + 1) / 2) << endl;

    return 0;
}