#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int k;
    string s;
    cin >> k >> s;

    if(s.size() <= k) cout << s << endl;
    else cout << s.substr(0,k) << "..." <<  endl;
    
    return 0;
}