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





void code(int TC){
    string s; cin >> s;
    deque<char> c;
    int n = s.size();
    int x; cin >> x;
    int cur = n;
    for(int i = 0; i < n; i++){
        if(cur >= x){
            x--;
            while(x > 0 && !c.empty()) c.pop_front(), x--;
            if(!c.empty()){
                cout << c.front();
                return;
            }
            while(x > 0) i++, x--;
            cout << s[i];
            return;
        }
        while(!c.empty() && cur < x && c.back() > s[i]) c.pop_back(), x -= cur, cur--;
        if(cur >= x){
            x--;
            while(x > 0 && !c.empty()) c.pop_front(), x--;
            if(!c.empty()){
                cout << c.front();
                return;
            }
            while(x > 0) i++, x--;
            cout << s[i];
            return;
        }
        c.push_back(s[i]);
    }
    while(x > cur) c.pop_back(), x -= cur, cur--;
    x--;
    while(x > 0) c.pop_front(), x--;
    cout << c.front();
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    cout.precision(30);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}