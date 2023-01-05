#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;

    // 正しいカッコ列かを判定する
    auto judge = [&](string &S) -> bool {
        bool res = true;
        int dep = 0;
        for(auto&& c: S){
            dep += (c == '(' ? 1 : -1);
            if(dep < 0) res = false;
        }
        if(dep != 0) res = false;
        return res;
    };

    vector<string> ans;

    // Bit全探索
    for(int Bit = 0; Bit < (1 << N); Bit++){
        string S = "";
        for(int i = 0; i < N; i++){
            if(Bit >> i & 1){
                S += ')';
            }else{
                S += '(';
            }
        }
        if(judge(S)){
            ans.push_back(S);
        }
    }

    // 辞書順に出力
    sort(ans.begin(), ans.end());
    for(auto&& S: ans) cout << S << endl;
    return 0;
}