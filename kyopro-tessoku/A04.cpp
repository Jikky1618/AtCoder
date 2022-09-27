#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int to_binary(int num){
    int ans = 0,base = 1;
    while(num > 0){
        ans += (num % 2) * base;
        num /= 2;
        base *= 10;
    }
    return ans;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    scanf("%d",&n);

    printf("%010d",to_binary(n));
    return 0;
}