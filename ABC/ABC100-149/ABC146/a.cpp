#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;
    
    vector<string> week = {"SUN","MON","TUE","WED","THU","FRI","SAT"};

    for(int i = 0; i < week.size(); i++){
        if(s == week[i]){
            cout << 7 - i << endl;
        }
    }
    return 0;
}