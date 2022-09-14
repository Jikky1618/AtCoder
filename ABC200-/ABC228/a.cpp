#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int s,t,x;
    cin >> s >> t >> x;

    if(s < t){
        if(s <= x && x < t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else{
        if(s <= x && x < 24 || 0 <= x && x < t) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}