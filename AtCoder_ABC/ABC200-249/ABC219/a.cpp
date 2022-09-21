#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int x;
    cin >> x;
    
    if(0 <= x && x < 40) cout << 40 - x << endl;
    else if(40 <= x && x < 70) cout << 70 - x << endl;
    else if(70 <= x && x < 90) cout << 90 - x <<endl;
    else cout << "expert" << endl;
    
    return 0;
}