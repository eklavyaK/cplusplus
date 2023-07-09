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
    int n,k,x; cin>>n>>k>>x;
    if(x==1 && k==1){
        cout<<"NO"<<endl;
    }
    else if(x==1){
        if(k==2){
            if(n&1) cout<<"NO"<<endl;
            else{
                cout<<"YES"<<endl;
                int t = n/2;
                cout<<t<<endl;
                while(t--){
                    cout<<2<<' ';
                }
                cout<<endl;
            }
        }
        else{
        cout<<"YES"<<endl;
            vector<int> v;
            while(n>0){
                if(n%3==0){
                    n/=3;
                    while(n--)v.push_back(3);
                    break;
                }
                else v.push_back(2);
                n-=2;
            }
            cout<<v.size()<<endl;
            for(auto i : v) cout<<i<<" ";cout<<endl;
        }
    }
    else{
        cout<<"YES"<<endl;
        cout<<n<<endl;
        while(n--){
            cout<<1<<' ';
        }
        cout<<endl;
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