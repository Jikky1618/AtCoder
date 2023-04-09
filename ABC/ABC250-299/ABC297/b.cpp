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

    int N = S.size();
    // 1つめの条件
    vector<int> pos_B;
    for(int i = 0; i < N; i++){
        if(S[i] == 'B') pos_B.push_back(i);
    }

    if(pos_B[0] % 2 == pos_B[1] % 2){
        cout << "No" << endl;
        return 0;
    }

    // 2つめの条件
    int pos_K = -1;
    for(int i = 0; i < N; i++){
        if(S[i] == 'K'){
            pos_K = i;
            break;
        }
    }
    vector<int> pos_R;
    for(int i = 0; i < N; i++){
        if(S[i] == 'R') pos_R.push_back(i);
    }

    if(pos_R[0] < pos_K && pos_K < pos_R[1]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}