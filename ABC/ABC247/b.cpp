#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin >> n;
    vector<string> s(n),t(n);
    for(int i = 0; i < n; i++) cin >> s[i] >> t[i];

    string nick;
    for(int i = 0; i < n; i++){
        bool can1 = true,can2 = true;
        nick = s[i];
        for(int j = 0; j < n; j++){
            if(nick == s[j] && i != j || nick == t[j] && i != j) can1 = false;
        }
        nick = t[i];
        for(int j = 0; j < n; j++){
            if(nick == s[j] && i != j || nick == t[j] && i != j) can2 = false;
        }
        if(!can1 && !can2){
            cout << "No" << endl;
            return 0;
        }
    }

    cout << "Yes" << endl;

    return 0;
}