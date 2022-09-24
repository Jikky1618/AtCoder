#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n,x;
    string s;
    cin >> n >> x >> s;

    int point = x;
    for(int i = 0; i < n; i++){
        if(s[i] == 'o') point++;
        else if(s[i] == 'x') point = max(point - 1,0);
    }

    cout << point << endl;
    
    return 0;
}