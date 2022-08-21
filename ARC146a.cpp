#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<string> num(N);
    for(int i = 0; i < N; i++) cin >> num[i];

    sort(num.begin(),num.end(),greater<string>());

    int max = 0,value = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            int k = 3 - i - j;
            if(i != j){
                value = stoi(num[i] + num[j] + num[k]);
                if(value > max) max = value;
            }
        }
    }

    cout << max << endl;

    return 0;
}