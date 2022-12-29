#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    cin >> N >> S;

    deque<char> d;
    for(auto c: S) d.push_back(c);

    if(d.size() % 2 == 0){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    while(1){
        bool flag = false;
        if(d.size() == 1 && d.front() == 'b') break;
        if(d.front() == 'a' && d.back() == 'c') ans++, flag = true;
        if(d.front() == 'c' && d.back() == 'a') ans++, flag = true;
        if(d.front() == 'b' && d.back() == 'b') ans++, flag = true;
        if(!flag) break;
        d.pop_front(); d.pop_back();
    }

    cout << ans << endl;
    return 0;
}