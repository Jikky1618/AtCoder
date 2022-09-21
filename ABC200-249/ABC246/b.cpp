#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    double a,b;
    cin >> a >> b;

    double x_ans,y_ans;
    x_ans = a / sqrt(a*a + b*b);
    y_ans = b / sqrt(a*a + b*b);

    cout << x_ans << " " << y_ans << endl;
    return 0;
}