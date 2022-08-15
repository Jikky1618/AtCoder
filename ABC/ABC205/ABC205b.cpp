#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    bool flag = true;
    for(int i = 0; i < n - 1; i++){
        if(a[i + 1] - a[i] != 1) flag = false;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}