#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string W;
    cin >> W;

    string a = "aiueo";
    for(auto c: W){
        if(a.find(c) == string::npos) cout << c;
    }
    cout << endl;
    return 0;
}