#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> p(n);
    for(int i = 0; i < n; i++){
        cin >> p[i].first >> p[i].second;
    }

    double max = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            int dist_x = abs(p[i].first - p[j].first);
            int dist_y = abs(p[i].second - p[j].second);
            double dist = pow(pow(dist_x, 2)+pow(dist_y, 2),0.5);
            if(dist > max) max = dist;
        }
    }

    printf("%lf\n",max);

    return 0;
}