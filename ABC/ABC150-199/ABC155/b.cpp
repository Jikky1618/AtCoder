#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    bool can = true;
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            if(a[i] % 3 != 0 && a[i] % 5 != 0) can = false;
        }
    }

    if(can) cout << "APPROVED" << endl;
    else cout << "DENIED" << endl;
    
    return 0;
}