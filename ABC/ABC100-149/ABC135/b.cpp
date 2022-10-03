#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];
    
    vector<int> a(n);
    for(int i = 0; i < n; i++) a[i] = i + 1;
    int diff = 0;
    for(int i = 0; i < n; i++){
        if(p[i] != a[i]) diff++;
    }
    
    if(diff == 0 || diff == 2){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }

    return 0;
}