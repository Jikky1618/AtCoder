#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int x_1,x_2,x_3,y_1,y_2,y_3;
    int x_ans,y_ans;
    cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;

    if(x_1 == x_2) x_ans = x_3;
    if(x_1 == x_3) x_ans = x_2;
    if(x_2 == x_3) x_ans = x_1;

    if(y_1 == y_2) y_ans = y_3;
    if(y_1 == y_3) y_ans = y_2;
    if(y_2 == y_3) y_ans = y_1;

    cout << x_ans << " " << y_ans << endl;

    return 0;
}