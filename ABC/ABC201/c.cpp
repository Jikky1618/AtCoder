#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    // input
    string str;
    cin >> str;

    int ans = 0;
    for (int i = 0; i <= 9999; i++){ // 0~9999の全探索
        vector<bool> num(10);
        int pass = i;

        // 1～10の配列にpassの各桁を代入
        for(int j = 0; j < 4; j++){
            num[pass % 10] = true;
            pass /= 10;
        }

        // Check
        bool flag = true;
        for(int j = 0; j < 10; j++){
            if(str[j] == 'o' && !num[j]) flag = false;
            if(str[j] == 'x' && num[j]) flag = false;
        }
        if(flag) ans++;
    }

    // Output
    cout << ans << endl;

    return 0;
}