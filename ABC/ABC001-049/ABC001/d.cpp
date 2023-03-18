#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#ifdef LOCAL
#include <debug_print.hpp>
#define debug(...) debug_print::multi_print(#__VA_ARGS__, __VA_ARGS__)
#else
#define debug(...) (static_cast<void>(0))
#endif

// 文字列 -> 数に変換
int conv1(string S){
    return (S[0] - '0') * 600 + (S[1] - '0') * 60 + (S[2] - '0') * 10 + (S[3] - '0');
}

// 数 -> 文字列に変換 
string conv2(int T){
    string res = "";
    res += T / 600 + '0', T %= 600;
    res += T / 60 + '0', T %= 60;
    res += T / 10 + '0', T %= 10;
    res += T + '0';
    return res;
}

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> S(N), E(N);
    for(int i = 0; i < N; i++){
        string str; cin >> str;
        S[i] = conv1(str.substr(0, 4));
        E[i] = conv1(str.substr(5, 8));
    }

    for(int i = 0; i < N; i++){
        S[i] = S[i] / 5 * 5;
        E[i] = (E[i] + 4) / 5 * 5;
    }

    vector<pair<int, int>> T(N);
    for(int i = 0; i < N; i++) T[i] = {S[i], E[i]};

    sort(T.begin(), T.end());

    vector<pair<int, int>> ans;
    ans.push_back(T[0]);

    for(int i = 1; i < N; i++){
        if(ans.back().second < T[i].first){
            ans.push_back(T[i]);
        }else{
            ans.back().second = max(ans.back().second, T[i].second);
        }
    }

    for(auto e: ans){
        cout << conv2(e.first) << "-" << conv2(e.second) << endl;
    }
}