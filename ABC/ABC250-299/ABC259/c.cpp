#include <bits/stdc++.h>
using namespace std;
using ll = long long;


#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

vector<pair<char, int>> run_length_encodeing(const string& S) {
    vector<pair<char, int>> res;
    for (auto c : S) {
        if (!res.empty() && c == res.back().first) {
            res.back().second++;
        } else {
            res.emplace_back(c, 1);
        }
    }
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    string S, T;
    cin >> S >> T;
    auto S2 = run_length_encodeing(S), T2 = run_length_encodeing(T);
    
    if(S2.size() != T2.size()){
        cout << "No" << endl;
        return 0;
    }

    debug(S2, T2);
    bool flag = true;
    for(unsigned i = 0; i < S2.size(); i++){
        // 文字が異なる時点で一致できない
        if(S2[i].first != T2[i].first) flag = false;
        // 文字数が異なり, S > T または, S が 1 文字なら一致できない
        if(S2[i].second != T2[i].second && (S2[i].second == 1 || S2[i].second > T2[i].second)) flag = false;
    }

    cout << (flag ? "Yes" : "No") << endl;
}