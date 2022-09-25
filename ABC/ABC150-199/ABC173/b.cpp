#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) cin >> s[i];

    int AC = 0,WA = 0,TLE = 0,RE = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == "AC") AC++;
        if(s[i] == "WA") WA++;
        if(s[i] == "TLE") TLE++;
        if(s[i] == "RE") RE++;
    }

    cout << "AC x " << AC << endl;
    cout << "WA x " << WA << endl;
    cout << "TLE x " << TLE << endl;
    cout << "RE x " << RE << endl;

    return 0;
}