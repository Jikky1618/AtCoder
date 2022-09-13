#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> p(n);
    for(int i = 0; i < n; i++) cin >> p[i];

    vector<int> count(n);
    for(int i = 0; i < n; i++){
        for(int j = -1; j <= 1; j++){
            count[(p[i]-i+j+n)%n]++;
        }
    }
    sort(count.begin(), count.end(),greater<int>());

    cout << count[0] << endl;

    return 0;
}