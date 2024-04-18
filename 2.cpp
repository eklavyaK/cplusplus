#include<bits/stdc++.h>
#define endl "\n"
#define ff first
#define ss second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a, n) 42
#define debug(...) 42
#endif



const ld pi = 3.14159265359;

void code(int TC){
    ld h, a; cin >> h >> a;
    ld H = h, refine = 1000;
    ld r = 100;
    ld mh = h / refine, mr = r / refine, all = 0, s = 0, l = 0;
    r = mr;
    for(int i = 1; i <= refine; i++){
        int pts = pi * (r * r - l * l) / a;
        all += pts;
        s += pts * (h * h);
        h -= mh;
        l = r;
        r += mr;
    }
    cout << H * sqrt((ld) 1 / 6) << endl;
    cout << sqrt(s / all) << endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    cout.precision(30);
    int TT = 1;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}