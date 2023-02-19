#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S;
    cin >> S;

    // Sの使用している文字の数
    vector<int> cnt(10);
    for(auto c: S) cnt[c - '0']++;

    if(S.size() == 1 && S == "8"){
        cout << "Yes" << endl;
        return 0;
    }
    if(S.size() == 2){
        if(stoi(S) % 8 == 0){
            cout << "Yes" << endl;
            return 0;
        }
        swap(S[0], S[1]);
        if(stoi(S) % 8 == 0){
            cout << "Yes" << endl;
            return 0;
        }
    }

    for(int i = 0; i <= 999; i++){
        string T = to_string(i);
        
        vector<int> cnt2(10);
        for(auto c: T) cnt2[c - '0']++;
        cnt2[0] += 3 - T.size();

        bool flag = true;
        debug(cnt2, cnt);
        for(int j = 0; j < 10; j++){
            if(cnt2[j] > cnt[j]) flag = false;
        }

        if(flag && i % 8 == 0){
            cout << "Yes" << endl;
            debug(i);
            return 0;
        }
    }

    cout << "No" << endl;
}