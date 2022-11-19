#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<char, int>> rle(string& s){
    int n = s.size();
    vector<pair<char, int>> res;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if (s[i] != s[i + 1]){
            res.push_back({s[i], cnt});
            cnt = 1;
        }
        else cnt++;
    }

    res.push_back({s.back(), cnt});
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s,t;
    cin >> s >> t;
    auto s2 = rle(s), t2 = rle(t);
    
    if(s2.size() != t2.size()){
        cout << "No" << endl;
        return 0;
    }

    bool flag = true;
    for(int i = 0; i < (int)s2.size(); i++){
        if(s2[i].first != t2[i].first) flag = false;
        if(s2[i].second != t2[i].second && (s2[i].second > t2[i].second || s2[i].second == 1)) flag = false;
    }

    if(flag) cout << "Yes" << endl;
    endl cout << "No" << endl;
    return 0;
}