#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    // Input
    int a,b,c;
    cin >> a >> b >> c;

    // pow(a,c),pow(b,c)の符号check
    int _ac = c % 2 == 1 && a < 0;
    int _bc = c % 2 == 1 && b < 0;

    //Check
    if(_ac == _bc){
        if(abs(a) > abs(b)) cout << ">" << endl;
        if(abs(a) < abs(b)) cout << "<" << endl;
        if(abs(a) == abs(b)) cout << "=" << endl;
    }else{
        if(a < 0) cout << "<" << endl;
        if(b < 0) cout << ">" << endl;
    }
    
    return 0;
}