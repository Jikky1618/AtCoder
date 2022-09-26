#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    int n = s.size();

    string revS = s;
    reverse(revS.begin(), revS.end());
    string revS1 = s.substr(0,(n - 1) / 2);
    reverse(revS1.begin(), revS1.end());
    string revS2 = s.substr((n + 3) / 2 - 1);
    reverse(revS2.begin(), revS2.end());

    if(s == revS && s.substr(0,(n - 1) / 2) == revS1 && s.substr((n + 3) / 2 - 1) == revS2){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    
    return 0;
}