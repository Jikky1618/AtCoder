#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string a,b;
    int k;
    cin >> k >> a >> b;

    ll a_Sum = 0,b_Sum = 0,digits;
    for(int i = a.size() - 1,digits = 1; i >= 0; i--){
        a_Sum += (a[i] - '0') * digits;
        digits *= k;
    }
    for(int i = b.size() - 1,digits = 1; i >= 0; i--){
        b_Sum += (b[i] - '0') * digits;
        digits *= k;
    }
    cout << (a_Sum * b_Sum) << endl;

    return 0;
}