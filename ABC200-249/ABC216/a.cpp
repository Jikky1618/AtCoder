#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    double num;
    cin >> num;
    int x = (int)num;
    int y = (num - x) * 10;
    
    if(0 <= y && y <= 2) cout << x << "-" << endl;
    else if(3 <= y && y <= 6) cout << x << endl;
    else if(7 <= y && y <= 9) cout << x << "+" << endl;

    return 0;
}