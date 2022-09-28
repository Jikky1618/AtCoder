#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    if(s.substr(0,n / 2) == s.substr(n / 2)){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}