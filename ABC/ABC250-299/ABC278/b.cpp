#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int check(int h,int m){
    return (0 <= h && h <= 23 && 0 <= m && m <= 59);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int h,m;
    cin >> h >> m;

    while(1){
        int a = h / 10, b = h % 10, c = m / 10, d = m % 10;
        int rev_h = a * 10 + c;
        int rev_m = b * 10 + d;
        if(check(rev_h, rev_m)){
            cout << h << " " << m << endl;
            return 0;
        }
        m++;
        if(m % 60 == 0) m = 0, h++;
        if(h % 24 == 0) h = 0;
    }
    return 0;
}