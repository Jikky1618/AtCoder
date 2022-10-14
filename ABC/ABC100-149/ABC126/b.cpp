#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    int s1 = (s[0] - '0') * 10 + (s[1] - '0');
    int s2 = (s[2] - '0') * 10 + (s[3] - '0');

    if(1 <= s1 && s1 <= 12 && 1 <= s2 && s2 <= 12){
        cout << "AMBIGUOUS" << endl;
    }
    if(!(1 <= s1 && s1 <= 12) && 1 <= s2 && s2 <= 12){
        cout << "YYMM" << endl;
    }
    if(1 <= s1 && s1 <= 12 && !(1 <= s2 && s2 <= 12)){
        cout << "MMYY" << endl;
    }
    if(!(1 <= s1 && s1 <= 12) && !(1 <= s2 && s2 <= 12)){
        cout << "NA" << endl;
    }

    return 0;
}