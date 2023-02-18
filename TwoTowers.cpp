#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;



void code(){
    int n,m; cin>>n>>m;
    string s,c; cin>>s>>c;
    reverse(c.begin(),c.end());
    string sa = s+c;
    int k = 0;
    for(int i=1;i<n+m;i++){
        if(sa[i]==sa[i-1]){
            k++;
        }
    }
    if(k<=1){
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