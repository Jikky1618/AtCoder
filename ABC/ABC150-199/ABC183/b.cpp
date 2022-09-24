#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    double sx,sy,gx,gy;
    scanf("%lf%lf%lf%lf",&sx,&sy,&gx,&gy);

    gy *= -1; // 点Gをx軸について対称移動
    double slope = (gy - sy) / (gx - sx); // 傾き
    double intercept = sy - sx * slope; // 切片
    double ans_x = (intercept / slope) * -1;

    printf("%.10lf",ans_x);

    return 0;
}