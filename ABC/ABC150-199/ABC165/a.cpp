#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k,a,b;
    cin >> k >> a >> b;
    
    for(int i = a; i <= b; i++){
        if(i % k == 0){
            cout << "OK" << endl;
            return 0;
        }
    }

    cout << "NG" << endl;
    
    return 0;
}