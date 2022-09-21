#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int INF = 1e9;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];
    vector<int> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    double res = 0;
    for(int i = 0; i < n; i++){
            double min = INF,dist_x,dist_y,dist;
        for(int j = 0; j < k; j++){
            dist_x = x[i] - x[a[j] - 1];
            dist_y = y[i] - y[a[j] - 1];
            dist = sqrt(dist_x * dist_x + dist_y * dist_y);
            if(min > dist) min = dist;
        }
        if(res < min) res = min;
    }

    printf("%lf",res);

    return 0;
}


