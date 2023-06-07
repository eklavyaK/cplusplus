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
    vector<int> arr(n);
    int x = 0, y = 0, z = 0;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        if(k==1) x = i+1;
        else if(k==2) y = i+1;
        else if(k==n) z = i+1;
    }
    int l = min({x,y,z});
    int r = max({x,y,z});
    if(z<r && z>l){
        cout<<1<<' '<<1<<endl;
    }
    else if(z==l){
        if(x==r){
            cout<<z<<' '<<y<<endl;
        }
        else cout<<z<<" "<<x<<endl;
    }
    else{
        if(x==l){
            cout<<z<<' '<<y<<endl;
        }
        else cout<<z<<' '<<x<<endl;
    }
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}