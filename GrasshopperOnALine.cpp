#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int x,k; cin>>x>>k;
    if(x%k==0){
        cout<<2<<endl;
        cout<<1<<endl;
        cout<<x-1<<endl;
    }
    else{
        cout<<1<<endl;
        cout<<x<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}