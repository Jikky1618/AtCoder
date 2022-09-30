#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define debug(x) cerr << "\033[33m[" << __LINE__ << "] " << #x << ": " << x << "\033[m" << endl;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    for(int bit = 0; bit < (1 << 3); bit++){
        int calc = s[0] - '0';
        for(int i = 0; i < 3; i++){
            if((bit >> i) & 1){
                calc += (s[i + 1] - '0');
            }else{
                calc -= (s[i + 1] - '0');
            }
        }

        if(calc == 7){
            cout << s[0];
            for(int i = 0; i < 3; i++){
                if((bit >> i) & 1){
                    cout << '+';
                }else{
                    cout << '-';
                }
                cout << s[i + 1];
            }
            cout << "=7" << endl;
            return 0;
        }
    }
}