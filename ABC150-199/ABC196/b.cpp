#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string x;
    cin >> x;

    bool Decimal = false;
    for(int i = 0; i < x.size(); i++){
        if(x[i] == '.') Decimal = true;
    }
    if(Decimal){
        while(x[x.size() - 1] != '.') x.pop_back();
        x.pop_back(); // clear "."
    }

    cout << x << endl;

    return 0;
}