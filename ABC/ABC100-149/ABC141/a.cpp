#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    string s;
    cin >> s;

    vector<string> weather = {"Sunny","Cloudy","Rainy","Sunny"};
    for(int i = 0; i < 3; i++){
        if(s == weather[i]){
            s = weather[i + 1];
            break;
        }
    }

    cout << s << endl;
    return 0;
}