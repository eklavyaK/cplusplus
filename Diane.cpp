#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n; cin>>n;
    if(n&1){
        if(n==1)cout<<'a'<<endl;
        else{
            int k = (n-2)/2;
            cout<<string(k,'a')<<"bc"<<string(k+1,'a')<<endl;
        }
    }
    else{
        cout<<string(n/2,'a')<<"b"<<string(n/2-1,'a')<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}