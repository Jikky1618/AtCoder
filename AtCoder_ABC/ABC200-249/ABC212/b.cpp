#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    if(s[0] == s[1] && s[1] == s[2] && s[2] == s[3]){
        cout << "Weak" << endl;
        return 0;
    }
    for(int i = 0; i < 3; i++){
        if(s[i + 1] - s[i] != 1 && s[i] - s[i + 1] != 9){
            cout << "Strong" << endl;
            return 0;
        }
    }
    cout << "Weak" << endl;

    return 0;
}