#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,k;
    cin >> n >> k;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= k; j++){
            sum += 100 * i + j;
        }
    }
    cout << sum << endl;
    
    return 0;
}