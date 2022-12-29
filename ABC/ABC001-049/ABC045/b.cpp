#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<deque<char>> S(3);
    for(int i = 0; i < 3; i++){
        string s; cin >> s;
        for(auto c: s) S[i].push_back(c);
    }

    int pos = 0, np = 0; // Aさんからスタート
    for(int i = 0; i < 300; i++){
        np = S[pos].front() - 'a';
        if(S[pos].empty()){
            cout << (char)(pos + 'A') << endl;
            break;
        }
        S[pos].pop_front();
        pos = np;
    }
    return 0;
}