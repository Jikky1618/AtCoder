#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string shiftR(string s){
    s = s[s.size()-1] + s;
    s.pop_back();
    return s;
}

int main(){
    string s;
    cin >> s;
    
    string min = s,max = s;
    for(int i = 0; i < s.size(); i++){
        s = shiftR(s);
        if(s < min) min = s;
        if(s > max) max = s;
    }

    cout << min << endl << max << endl;

    return 0;
}