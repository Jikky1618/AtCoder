#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    
    int sum = 0;
    for(int i = 0; i < n; i++){
        if(a[i] > 10) sum += a[i] - 10;
    }
    cout << sum << endl;

    return 0;
}