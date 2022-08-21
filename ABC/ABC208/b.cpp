#include <bits/stdc++.h>
using namespace std;

int main(){
    int p;
    cin >> p;
    vector<int> factorial(11);
    factorial[0] = 1;
    // 1-index
    for(int i = 1; i <= 10; i++){
        factorial[i] = i * factorial[i - 1];
    }
    
    int ans = 0;
    for(int i = 10; i >= 1; i--){
        while(factorial[i] <= p){
            p -= factorial[i];
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}