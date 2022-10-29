#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string n;
    cin >> n;

    if(equal(n.begin(),n.end(),n.rbegin())){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}