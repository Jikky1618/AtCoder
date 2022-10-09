#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int W,H,x,y;
    cin >> W >> H >> x >> y;

    double ans_1; int ans_2;
    ans_1 = (double)(W) * H / 2;
    if(x * 2 == W && y * 2 == H){
        ans_2 = 1;
    }else{
        ans_2 = 0;
    }

    printf("%.10lf %d\n",ans_1, ans_2);
    return 0;
}