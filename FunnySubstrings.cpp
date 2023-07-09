#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;
#ifndef ONLINE_JUDGE
#include "include/debug.h"
#else
#define debugarr(a,n) 42
#define debug(...) 42
#endif

#define tp tuple<int,string,string>

tp analyse(string s){
    int a = 0;
    string b = "", c = "";
    if(s.find("haha")!=-1) a = 1;
    if(s.size()>3) b = s.substr(0,3), c = s.substr(s.size()-3);
    else b = c = s;
    return {a,b,c};
}
tp concatenate(tp l, tp r){
    string s = get<2>(l) + get<1>(r);
    int a = get<0>(l) + get<0>(r);
    if(s.size()>=4) a += s.substr(0,4)=="haha";
    if(s.size()>=5) a += s.substr(1,4)=="haha";
    if(s.size()>=6) a += s.substr(2,4)=="haha";
    string b = "", c = "";
    if(get<1>(l).size()<3){
        b = get<1>(l) + get<1>(r);
        if(b.size()>3) b = b.substr(0,3);
    }
    else b = get<1>(l).substr(0,3);
    if(get<2>(r).size()<3){
        c = get<2>(l) + get<2>(r);
        if(c.size()>3) c = c.substr(c.size()-3);
    }
    else c = get<2>(r).substr(get<2>(r).size()-3);
    return {a,b,c};
}
void code(int TC){
    int n; cin>>n;
    map<string,tp> m;
    int ans = 0;
    while(n--){
        string var, type; cin>>var>>type;
        if(type==":="){
            string add; cin>>add;
            m[var] = analyse(add);
        }
        else{
            string a, sign, b; cin>>a>>sign>>b;
            m[var] = concatenate(m[a],m[b]);
        }
        ans = get<0>(m[var]);
        auto[a,b,c] = m[var];
        debug(a,b,c);
    }
    cout<<ans<<endl;
}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}