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
    int b = 0, z = 0;
    bool f = true;
    for(int i=0;i<n;i++){
        int l, r; cin>>l>>r;
        if(l==k) b++;
        if(r==k) z++;
    }
    if(b>0 && z>0){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}