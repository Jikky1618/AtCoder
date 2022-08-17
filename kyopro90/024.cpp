#include <bits/stdc++.h>
using namespace std;

int main(void){

    // Input
    int n,k;
    cin >> n >> k;
    vector<int> a(n),b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    // Check diff
    long long int diff = 0;
    for(int i = 0; i < n; i++){
        diff += abs(a[i] - b[i]);
    }
    if(diff > k){
        cout << "No" << endl;
        return 0;
    }

    // Check parity
    if(k % 2 != diff % 2){
        cout << "No" << endl;
        return 0;
    }
    
    // Output
    cout << "Yes" << endl;

    return 0;
}