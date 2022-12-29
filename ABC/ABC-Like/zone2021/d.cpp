#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    deque<char> d;
    bool rev = false; // 反転しているか
    for(auto c: S){
        if(c == 'R') rev ^= 1;
        else if(rev) d.push_front(c);
        else d.push_back(c);
    }
    if(rev) reverse(d.begin(), d.end());

    string T;
    for(auto c: d){
        if(T.size() && T.back() == c) T.pop_back();
        else T.push_back(c);
    }

    cout<< T << endl;
    return 0;
}