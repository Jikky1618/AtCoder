#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,a,b;
    cin >> n >> a >> b;
    cout << min(n * a,b) << endl;
    return 0;
}