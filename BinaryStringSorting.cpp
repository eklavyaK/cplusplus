#include<bits/stdc++.h>
#define endl "\n"
#define F first
#define S second
#define int long long
typedef long long ll;
typedef long double ld;
using namespace std;

const int l = 1e12, r = 1e12+1;

void code(){
    string s; cin>>s;
    int n = s.size();
    int forward_count[n+2]{}, backward_count[n+2]{};
    if(s == string(n,'0')||s == string(n,'1')){
        cout<<0<<endl;
        return;
    }
    int cnt = 0;
    for(int i=1;i<=n;i++){
        forward_count[i] = forward_count[i-1] + (s[i-1]=='1');
        
    }
    for(int i=n;i>=1;i--){
        backward_count[i] = backward_count[i+1] + (s[i-1]=='0');
    }
    int b[n+2]{}, f[n+2]{};
    for(int i=n;i>=1;i--){
        if(s[i-1]=='1')continue;
        int k = 0;
        while(i-1>=0 && s[i-1]=='0')i--, k++;
        b[i] = k;
    }
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0')continue;
        int k = 0;
        while(i-1<n && s[i-1]=='1')i++, k++;
        f[i] = k;
    }
    int ans = min(backward_count[1]*r,forward_count[n]*r);
    for(int i=1;i<=n;i++){
        if(s[i-1]=='0'){
            ans = min(ans,backward_count[i+1]*r+(forward_count[i-1]-f[i])*r+f[i]*l); 
        }
        else{
            ans = min(ans,(backward_count[i+1]-b[i])*r+b[i]*l+forward_count[i-1]*r);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin>>t; while(t--)code();
    return 0;
}