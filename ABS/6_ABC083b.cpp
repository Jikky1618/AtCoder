#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n,a,b,res = 0;
    cin >> n >> a >> b;
    for(int i = 1; i <= n; i++){
        int num = i,sum = 0;
        //solve sum of digits
        while(num > 0){
            sum += num % 10;
            num /= 10;
            }
        
        if(a <= sum && sum <= b){
            res += i;
        }
    }
    cout << res << endl;
    
    return 0;
}