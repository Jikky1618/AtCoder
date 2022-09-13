#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;

    cout << (n * (n-1) + m * (m-1)) / 2 << endl;
    return 0;
}