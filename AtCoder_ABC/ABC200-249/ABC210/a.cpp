#include <bits/stdc++.h>
using namespace std;

int main() {
    int n,a,x,y;
    cin >> n >> a >> x >> y;
    int total = 0;
    if(n <= a){
        total = n * x;
    }else{
        total = a * x + (n - a) * y;
    }
    cout << total << endl;

    return 0; 
}