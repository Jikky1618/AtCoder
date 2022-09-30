#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    string base = "atcoder";
    vector<int> base_v(7);
    for(int i = 0; i < 7; i++) base_v[i] = i;

    vector<int> s_v(7);
    for(int i = 0; i < 7; i++){
        for(int j = 0; j < 7; j++){
            if(s[i] == base[j]) s_v[i] = j;
        }
    }

    // 転置数を求める
    int inversion = 0;
    for(int i = 0; i < 7; i++){
        for(int j = i + 1; j < 7; j++){
            if(s_v[i] > s_v[j]) inversion++;
        }
    }

    cout << inversion << endl;
    return 0;
}