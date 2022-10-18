#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; i++){
        // bit xのi桁目は1かどうか
        if((x >> i) & 1) sum += a[i];
    }

    cout << sum << endl;

    return 0;
}