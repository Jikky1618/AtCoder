#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int y = stoi(s.substr(0,4));
    int m = stoi(s.substr(5,2));

    if((y < 2019) || (y == 2019 && m < 5)){
        cout << "Heisei" << endl;
    }else{
        cout << "TBD" << endl;
    }

    return 0;
}