#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    vector<string> contents = {"ABC","ARC","AGC","AHC"};
    vector<bool> used(4);

    string str;
    for(int i = 0; i < 3; i++){
        cin >> str;
        for(int j = 0; j < 4; j++){
            if(contents[j] == str) used[j] = true;
        }
    }
    
    for(int i = 0; i < 4; i++){
        if(!used[i]) cout << contents[i] << endl;
    }

    return 0;
}