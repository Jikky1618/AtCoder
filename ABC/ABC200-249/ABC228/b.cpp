#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    vector<bool>known(n);
    for(int i = 0; i < n; i++){
        known[x - 1] = true;
        x = a[x - 1];
    }
    int count = 0;
    for(int i = 0; i < n; i++){
        if(known[i]) count++;
    }
    cout << count << endl;

    return 0;
}