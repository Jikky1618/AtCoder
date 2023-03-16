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
    int Deg, Dis;
    cin >> Deg >> Dis;

    Dis = round((Dis / 60.0) * 10);
    int W = -1;
    if(Dis < 3){
        W = 0;
    }else if(Dis < 16){
        W = 1;
    }else if(Dis < 34){
        W = 2;
    }else if(Dis < 55){
        W = 3;
    }else if(Dis < 80){
        W = 4;
    }else if(Dis < 108){
        W = 5;
    }else if(Dis < 139){
        W = 6;
    }else if(Dis < 172){
        W = 7;
    }else if(Dis < 208){
        W = 8;
    }else if(Dis < 245){
        W = 9;
    }else if(Dis < 285){
        W = 10;
    }else if(Dis < 327){
        W = 11;
    }else{
        W = 12;
    }

    Deg *= 10;
    string Dir = "";
    if(W == 0){
        Dir = "C";
    }else if(1125 <= Deg && Deg < 3375){
        Dir = "NNE";
    }else if(3375 <= Deg && Deg < 5625){
        Dir = "NE";
    }else if(5625 <= Deg && Deg < 7875){
        Dir = "ENE";
    }else if(7875 <= Deg && Deg < 10125){
        Dir = "E";
    }else if(10125 <= Deg && Deg < 12375){
        Dir = "ESE";
    }else if(12375 <= Deg && Deg < 14625){
        Dir = "SE";
    }else if(14625 <= Deg && Deg < 16875){
        Dir = "SSE";
    }else if(16875 <= Deg && Deg < 19125){
        Dir = "S";
    }else if(19125 <= Deg && Deg < 21375){
        Dir = "SSW";
    }else if(21375 <= Deg && Deg < 23625){
        Dir = "SW";
    }else if(23625 <= Deg && Deg < 25875){
        Dir = "WSW";
    }else if(25875 <= Deg && Deg < 28125){
        Dir = "W";
    }else if(28125 <= Deg && Deg < 30375){
        Dir = "WNW";
    }else if(30375 <= Deg && Deg < 32625){
        Dir = "NW";
    }else if(32625 <= Deg && Deg < 34875){
        Dir = "NNW";
    }else{
        Dir = "N";
    }

    cout << Dir << " " << W << endl;
}