#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,m,x,t,d;
    cin >> n >> m >> x >> t >> d;
    if(m > x) cout << t;
    else if(m <= x) cout << (d * m + t - d * x);
        
    return 0;
}