#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<pair<int, int>> P(N);
    for(int i = 0; i < N; i++) cin >> P[i].first >> P[i].second;

    sort(P.begin(), P.end(), [&](auto &A, auto &B){
        return A.second < B.second;
    });

    bool flag = true;
    int time = 0;
    for(int i = 0; i < N; i++){
        if(time + P[i].first <= P[i].second){
            time += P[i].first;
        }else{
            flag = false;
            break;
        }
    }

    cout << (flag ? "Yes" : "No") << endl;
}