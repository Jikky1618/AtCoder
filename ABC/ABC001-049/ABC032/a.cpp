#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int a, b, n;
    cin >> a >> b >> n;
    
    for(int i = n; i <= n * a * b; i++){
        if(i % a == 0 && i % b == 0){
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}