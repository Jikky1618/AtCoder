#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll a,b1,b2;
    scanf("%lld %lld.%lld",&a,&b1,&b2);

    ll ans = a * (b1 * 100 + b2);
    ans /= 100;

    printf("%lld",ans);
    
    return 0;
}