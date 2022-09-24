#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    scanf("%d",&n);
    vector<double> a(n);
    for(int i = 0; i < n; i++) scanf("%lf",&a[i]);

    double L1 = 0; // マンハッタン距離
    for(int i = 0; i < n; i++){
        L1 += abs(a[i]);
    }

    double L2 = 0; // ユークリッド距離
    for(int i = 0; i < n; i++){
        L2 += pow(abs(a[i]),2);
    }
    L2 = pow(L2,0.5); // sqrt(L2)

    double Linf = 0; // チェビシェフ距離
    for(int i = 0; i < n; i++){
        Linf = max(Linf,abs(a[i]));
    }

    printf("%.10lf\n%.10lf\n%.10lf",L1,L2,Linf);

    return 0;
}