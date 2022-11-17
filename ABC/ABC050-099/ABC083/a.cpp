#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a,b,c,d;
    cin >> a >> b >> c >> d;

    int left = a + b, right = c + d;
    if(left > right) cout << "Left" << endl;
    if(left < right) cout << "Right" << endl;
    if(left == right) cout << "Balanced" << endl;
    return 0;
}