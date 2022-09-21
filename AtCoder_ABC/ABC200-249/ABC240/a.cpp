#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int a,b;
    cin >> a >> b;
    
    if(b - a == 1 || b - a == 9){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    return 0;
}