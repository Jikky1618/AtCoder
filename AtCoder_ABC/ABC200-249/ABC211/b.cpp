#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<string> s(4);
    cin >> s[0] >> s[1] >> s[2] >> s[3];
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(i != j && s[i] == s[j]){
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;

    return 0;
}