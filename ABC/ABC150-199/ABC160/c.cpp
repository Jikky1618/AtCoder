#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k,n;
    cin >> k >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int Max = 0;
    for(int i = 1; i < n; i++){
        Max = max(Max, a[i] - a[i - 1]);
    }
    Max = max(Max, k - a[n - 1] + a[0]);
    cout << k - Max << endl;

    return 0;
}