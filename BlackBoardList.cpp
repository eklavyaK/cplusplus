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
    int mx = -1e9-5, mn = 1e9+5;
    for(int i=0;i<n;i++){
        int k; cin>>k;
        mn = min(mn,k);
        mx = max(mx,k);
    }
    if(mn<0){
        cout<<mn<<endl;
    }
    else cout<<mx<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}