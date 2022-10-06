#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    char b;
    cin >> b;
    if(b == 'A') cout << 'T' << endl;
    if(b == 'T') cout << 'A' << endl;
    if(b == 'C') cout << 'G' << endl;
    if(b == 'G') cout << 'C' << endl;
    return 0;
}