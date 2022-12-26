#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    char c;
    cin >> c;

    string V = "aiueo";
    if(V.find(c) != string::npos){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    return 0;
}