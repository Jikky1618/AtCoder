#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;
    
    int fmax = 2 * a + 100;
    cout << (fmax - b) << endl;
    
    return 0;
}