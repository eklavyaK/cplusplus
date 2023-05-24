
#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,k; cin>>n>>k;
    if((n&1) && (n+1)/2==k){
        cout<<"NO"<<endl;
        return;
    }
    if(n%2==0 && n/2==k){
        cout<<"YES"<<endl;
        return;
    }
    if((n+1)/2<k){
        cout<<"NO"<<endl;
        return;
    }
    if(((n+1)/2-k)%2==0){
        cout<<"YES"<<endl;
        return;
    }
    cout<<"NO"<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}