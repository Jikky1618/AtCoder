#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1);

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    
    double a,b,x;
    cin >> a >> b >> x;

    double s = x / a;
    double theta;
    if(s <= a * b / 2){
        theta = atan2(b * b, 2 * s);
    }else{
        theta = atan2(2 * (a * b - s), a * a);
    }

    theta = theta * 180 / PI;

    cout << theta << endl;
    return 0;
}