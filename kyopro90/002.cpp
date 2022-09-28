#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    vector<string> ans;
    for(int bit = 0; bit < (1 << n); bit++){
        string str;
        for(int i = 0; i < n; i++){
            // bitのi桁目が
            if((bit >> i) & 1) str += ")"; // 1なら")"
            else str += "("; // 0なら"("
        }
        // strが正しいカッコ列かどうかを表すflag
        bool correct = true;
        // ()を調べるための変数:  ( = set++, ) = set--
        int set = 0;
        for(int i = 0; i < n; i++){
            if(str[i] == '('){
                set++;
            }
            if(str[i] == ')'){
                set--;
            }
            if(set < 0) correct = false;
        }
        if(set != 0) correct = false;
        if(correct) ans.push_back(str);
    }
    
    sort(ans.begin(), ans.end());
    for(auto s: ans){
        cout << s << endl;
    }
    return 0;
}