#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<pair<char, int>> rle(string s){
    int n = s.size();
    vector<pair<char, int>> res;
    int cnt = 1;
    for(int i = 0; i < n; i++){
        if (s[i] != s[i + 1] || i == n - 1){
            res.push_back(pair<char,int>(s[i], cnt));
            cnt = 1;
        }
        else cnt++;
    }

    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string s;
    cin >> s;

    auto ans = rle(s);
    for(auto &&i: ans){
        cout << i.first << i.second;
    }
    cout << endl;
    return 0;
}