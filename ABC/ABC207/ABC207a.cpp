#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(void){
    int a,b,c;
    cin >> a >> b >> c;
    cout << (a + b + c) - min({a,b,c}) << endl;

    return 0;
}