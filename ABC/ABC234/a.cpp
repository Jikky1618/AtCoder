#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int fn(int n){
    int ans = n * n + 2 * n + 3;
    return ans;
}

int main(){
    int t;
    cin >> t;

    int res = fn(fn(fn(t) + t) + fn(fn(t)));

    cout << res << endl;

    return 0;
}