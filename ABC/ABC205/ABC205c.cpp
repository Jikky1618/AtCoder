#include <bits/stdc++.h>
using namespace std;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    int _ac = c % 2 == 1 && a < 0;
    int _bc = c % 2 == 1 && b < 0;
    if(_ac != _bc){
        cout << (_ac > _bc ? "<" : ">") << endl;
    }else{
        if(abs(a) == abs(b)) cout << "=" << endl;
        else cout << (abs(a) > abs(b) ? ">" : "<") << endl;
    }
    return 0;
}