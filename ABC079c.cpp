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
        vector<char> op(3);
        for(int i = 0; i < 3; i++){
            if((bit >> i) & 1){
                op[i] = '+';
            }else{
                op[i] = '-';
            }
        }

        int calc = s[0] - '0';
        for(int i = 0; i < 3; i++){
            if(op[i] == '+'){
                calc += (s[i + 1] - '0');
            }else{
                calc -= (s[i + 1] - '0');
            }
            if(calc == 7){
                cout << s[0] << op[0] << s[1] << op[1] <<  s[2] << op[2] << s[3] << "=7" << endl;
                return 0;
            }
        }
    }
    return 0;
}