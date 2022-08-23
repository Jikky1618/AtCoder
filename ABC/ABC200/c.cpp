#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<ll> mod(200);
    for(int i = 0; i < n; i++){
        mod[a[i] % 200]++;
    }

    ll total = 0;
    for(int j = 0; j < 200; j++){
        total += mod[j] * (mod[j] - 1) / 2; //mod[j]C2
    }
    cout << total << endl;

    return 0;
}