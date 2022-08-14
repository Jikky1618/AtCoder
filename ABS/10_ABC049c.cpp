#include <bits/stdc++.h>
using namespace std;

int main(void){
    string divide[4] = {"dream","dreamer","erase","eraser"};
    string s;
    cin >> s;
    // reverse s,divide
    reverse(s.begin(), s.end());
    for(int i = 0; i < 4; i++) reverse(divide[i].begin(), divide[i].end());
    
    bool can = true;
    for(int i = 0; i < s.size();){
        bool canDivide = false; // Can array Divide split string s?
        for(int j = 0; j < 4; j++){
            string d = divide[j];
            if(s.substr(i,d.size()) == d){ // Can d split string s?
                canDivide = true;
                i += d.size(); // Advance by the size of d
            }
        }
        if(!canDivide){
            can = false;
            break;
        }

    }
    if(can) cout << "YES" << endl;
    else cout << "NO" << endl;
    
    return 0;
}