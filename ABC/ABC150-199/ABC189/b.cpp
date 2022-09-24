#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    cin >> n >> x;
    vector<int> v(n),p(n);
    for(int i = 0; i < n; i++) cin >> v[i] >> p[i];

    int alcohol = 0;
    for(int i = 0; i < n; i++){
        alcohol += v[i] * p[i]; // alcohol += v[i] * p[i] / 100
        if(alcohol > x * 100){ // if(alcohol > x)
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}