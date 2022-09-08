#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n,x;
    cin >> n >> x;
    
    cout << (char)((x - 1) / n + 'A') << endl;

    return 0;
}