#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin >> N;
    vector<int> T(N);
    for(int i = 0; i < N; i++) cin >> T[i];
    
    cout << *min_element(T.begin(), T.end()) << endl;
    return 0;
}