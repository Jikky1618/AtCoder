#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;

    // Add (
    int set = 0,cnt = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            set++;
        }
        if(s[i] == ')'){
            set--;
        }
        if(set < 0){
            cnt = max(cnt, 0 - set);
        }
    }
    for(int i = 0; i < cnt; i++) s = '(' + s;

    n = s.size(); // nを更新
    // Add )
    set = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '('){
            set++;
        }
        if(s[i] == ')'){
            set--;
        }
    }
    for(int i = 0; i < set; i++){
        s = s + ')';
    }

    cout << s << endl;
    return 0;
}