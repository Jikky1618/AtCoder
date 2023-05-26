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
    vector<string> S(3);
    for(int i = 0; i < 3; i++) cin >> S[i];

    vector<char> chars;
    for(int i = 0; i < 3; i++){
        for(auto c: S[i]) chars.emplace_back(c);
    }
    sort(chars.begin(), chars.end());
    chars.erase(unique(chars.begin(), chars.end()), chars.end());
    if(chars.size() > 10){
        cout << "UNSOLVABLE" << endl;
        return 0;
    }

    vector<char> used(10, '.');
    auto check = [&]() -> bool {
        map<char, char> mp;
        for(int i = 0; i < 10; i++) if(used[i] != '.') mp[used[i]] = (char)('0' + i);
        string S1, S2, S3;
        for(auto c: S[0]) S1 += mp[c];
        for(auto c: S[1]) S2 += mp[c];
        for(auto c: S[2]) S3 += mp[c];

        // reading zero の有無
        if(to_string(stoll(S1)) != S1 || stoll(S1) == 0) return false;
        if(to_string(stoll(S2)) != S2 || stoll(S2) == 0) return false;
        if(to_string(stoll(S3)) != S3 || stoll(S3) == 0) return false;

        // 覆面算の確認
        if(stoll(S1) + stoll(S2) != stoll(S3)) return false;

        cout << S1 << "\n" << S2 << "\n" << S3 << "\n";
        return true;
    };

    // 使用している英小文字に 0 ~ 10 を割り当てる
    auto dfs = [&](auto&& self, int pos) -> bool {
        if(pos == (int)chars.size()) return check();
        
        for(int i = 0; i < 10; i++){
            if(used[i] != '.') continue;
            used[i] = chars[pos];
            if(self(self, pos + 1)) return true;
            used[i] = '.';
        }

        return false;
    };

    if(!dfs(dfs, 0)){
        cout << "UNSOLVABLE" << endl;
    }
}