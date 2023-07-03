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
#define debug(c)
#define debugarr(a,n)
#define debugvar(c)
#endif





void code(int TC){
    int T = 10;
    for(int i=0;i<T;i++){
        cout<<"#define deg(";
        for(int j=0;j<=i;j++){
            cout<<char(65+j)<<',';
        }
        cout<<") cerr<<\"=> \"";
        for(int j=0;j<=i;j++){
            cout<<"<<#"<<char(65+j)<<"<<\" \"";
        }
        cout<<"<<\"[\"";
        for(int j=0;j<=i;j++){
            cout<<"<<"<<char(65+j)<<"<<\" \"";
        }
        cout<<"<<\"]\"";
        cout<<"<<endl"<<endl;
    }

}


signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);cerr.tie(0);
    int TT = 1; cin >> TT;
    for (int TC = 1; TC <= TT; TC++) 
        code(TC);
    return 0;
}