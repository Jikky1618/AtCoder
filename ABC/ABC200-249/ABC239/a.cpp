#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    double h;
    scanf("%lf",&h);

    double ans = sqrt(h * (12800000 + h));

    printf("%lf",ans);

    return 0;
}