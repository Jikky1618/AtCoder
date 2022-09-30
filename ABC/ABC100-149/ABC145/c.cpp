#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> x(n),y(n);
    for(int i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<int> p;
    for(int i = 0; i < n; i++) p.push_back(i);
    double sum = 0,cnt = 0;
    do{
        for(int i = 0; i < n - 1; i++){
            double dist = sqrt(pow(x[p[i]] - x[p[i + 1]],2) + pow(y[p[i]] - y[p[i + 1]],2));
            sum += dist;
        }
        cnt++;
    }while(next_permutation(p.begin(), p.end()));
    double ans = sum / cnt;
    
    printf("%.10lf",ans);
    return 0;
}