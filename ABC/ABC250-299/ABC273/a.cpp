#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int f(int num){
    if(num == 0) return 1;
    return num * f(num - 1);
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    int ans = f(n);
    cout << ans << endl;

    return 0;
}