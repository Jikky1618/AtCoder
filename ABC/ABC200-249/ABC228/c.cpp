#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, K;
    cin >> N >> K;
    vector P(N, vector<int>(3));
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++) cin >> P[i][j];
    }

    vector<int> s(N);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < 3; j++) s[i] += P[i][j];
    }

    vector<int> tmp = s;
    sort(tmp.begin(), tmp.end(), greater<int>());

    for(int i = 0; i < N; i++){
        if(tmp[K - 1] <= s[i] + 300) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}