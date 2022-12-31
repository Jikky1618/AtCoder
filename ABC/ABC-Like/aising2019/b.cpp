#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, A, B;
    cin >> N >> A >> B;
    vector<int> P(N);
    for(int i = 0; i < N; i++) cin >> P[i];

    int one = 0, two = 0, three = 0;
    for(int i = 0; i < N; i++){
        if(P[i] <= A) one++;
        if(A < P[i] && P[i] <= B) two++;
        if(B < P[i]) three++;
    }

    cout << min({one, two, three}) << endl;
    return 0;
}