#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    string s;
    cin >> n >> s;
    
    deque<int> ans;
    for(int i = n - 1; i > 0; i--){
        if(s[i] == 'L') ans.push_back(i);
        else ans.push_front(i);
    }

    for(auto itr = ans.begin(); itr != ans.end(); itr++){
        cout << *itr << endl;
    }

    return 0;
}