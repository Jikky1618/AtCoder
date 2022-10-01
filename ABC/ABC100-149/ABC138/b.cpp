#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<double> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    double inv_sum = 0;
    for(int i = 0; i < n; i++){
        inv_sum += (1 / a[i]);
    }
    double ans = 1 / inv_sum;
    printf("%.10lf",ans);
    return 0;
}