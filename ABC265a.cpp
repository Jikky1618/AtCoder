#include <bits/stdc++.h>
using namespace std;

int main(){
    int x,y,n;
    cin >> x >> y >> n;
    
    int total = 0;
    if(3 * x > y){
        total = (n / 3) * y + (n % 3) * x;
    }else{
        total = n * x;
    }
    cout << total << endl;

    return 0;
}