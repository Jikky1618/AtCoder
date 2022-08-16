#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    int sum = 0;
    for(int i = 0; i < n; i++){
        if(i % 2 == 1) a[i]--;
        sum += a[i];
    }

    if(x >= sum) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0; 
}