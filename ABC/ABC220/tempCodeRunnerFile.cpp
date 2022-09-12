#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll n,x;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    cin >> x;

    ll sum_an = 0;
    for(int i = 0; i < n; i++) sum_an += a[i];

    int p = x / sum_an;
    int count = p * n;
    ll sum = p * sum_an;
    for(int i = 0; i < n; i++){
        sum += a[i];
        count++;
        if(sum > x) break;
    }

    cout << count << endl;

    return 0;
}