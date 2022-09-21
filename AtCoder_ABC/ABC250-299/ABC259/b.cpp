#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const double PI = acos(-1);

int main(){
    int a,b,d;
    scanf("%d%d%d",&a,&b,&d);

    double dist = sqrt(a * a + b * b);
    double theta = atan2(b,a);

    double ans_x = dist * cos(theta + d / 180.0 * PI);
    double ans_y = dist * sin(theta + d / 180.0 * PI);

    printf("%.10lf %.10lf",ans_x,ans_y);

    return 0;
}